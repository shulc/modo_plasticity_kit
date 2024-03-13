/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright (c) 2008-2022 The Foundry Group LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Helper classes for listening for tableau events and scheduling the tableau updates.
 */
#ifndef LX_TABLEAU_HPP
#define LX_TABLEAU_HPP

#include <lx_tableau.hpp>
#include <lx_item.hpp>

#include <map>
#include <vector>

//-----------------------------------------------------------------------------
// CLxTableauListener
//
// This is a generic class for adding tableau listeners.
//-----------------------------------------------------------------------------


class CLxTableauListener
{
public:

        // Call this from plugin init()
        static void Init();

        // Call this from plugin cleanup()
        static void Cleanup();

        // Add tableau listener (listens to all channels changes on given item)
        // If chanIndex is -1 then all changes are propagated, otherwise only channel
        // with given index will propagate the change back to source.
        // SourceT class needs to have method:
        //     LxResult TableauUpdate (ILxUnknownID tbxObj, ILxUnknownID itemObj, int chan)
        template< typename SourceT >
        static bool Add (
                                        SourceT*		source,
                                        ILxUnknownID	tableauObj,
                                        ILxUnknownID	item,
                                        int				chanIndex = -1);
private:

        //---------------------------------------------------------------------
        // Tableau update callback (helper class)
        //---------------------------------------------------------------------
        struct TbxUpdateCallback
        {
                typedef LxResult (*TableauUpdateFunc) (void*, ILxUnknownID, ILxUnknownID, int);

                //---------------------------------------------------------------------
                // Helper class to invoke TableauUpdate (specialized for type passed in the TbxUpdate constructor)
                //---------------------------------------------------------------------
                template< typename T >
                struct TableauUpdateStub
                {
                        // Stub function
                        static LxResult TableauUpdate (void* inst, ILxUnknownID tbx, ILxUnknownID item, int chan)
                        {
                                T* ptr = reinterpret_cast < T* > (inst);

                                return ptr->TableauUpdate (tbx, item, chan);
                        }
                };

                //---------------------------------------------------------------------
                // Default constructor
                //---------------------------------------------------------------------
                TbxUpdateCallback ()
                        : source (NULL)
                        , func (NULL)
                {
                }

                //---------------------------------------------------------------------
                // Constructor
                //---------------------------------------------------------------------
                template< typename SourceT >
                TbxUpdateCallback (SourceT*	src)
                        : source (src)
                        , func (TableauUpdateStub< SourceT >::TableauUpdate)
                {
                }

                //---------------------------------------------------------------------
                // Invoke TableauUpdate
                //---------------------------------------------------------------------
                LxResult TableauUpdate (ILxUnknownID tbx, ILxUnknownID item, int chan)
                {
                        if (source && func)
                                return func (source, tbx, item, chan);

                        return LXe_NOTFOUND;
                }

                // Members
                void*				source;			// Source instance
                TableauUpdateFunc	func;			// Pointer to function
        };

        // Forward declaration
        class UpdateVisitor;

        //-----------------------------------------------------------------------------
        // Tableau listener implementation
        //-----------------------------------------------------------------------------
        class Listener : public CLxImpl_TableauListener
        {
        public:

                Listener ();
                ~Listener ();

                void Add (ILxUnknownID tableauCtx, const TbxUpdateCallback& callback, ILxUnknownID item, int chan);

                // Called when item channel is changed
                        void
                tli_ChannelChange (
                        ILxUnknownID	tableauObj,
                        ILxUnknownID	itemObj,
                        int				chan) LXx_OVERRIDE;

                // Called when tableau is destroyed
                        void
                tli_TableauDestroy (
                        ILxUnknownID tableau) LXx_OVERRIDE;


        private:

                // Members
                struct Entry
                {
                        TbxUpdateCallback	callback;
                        ILxUnknownID		item;
                        int					chanIndex;
                };

                typedef std::vector< Entry >	EntryArray;

                EntryArray		m_entries;
                UpdateVisitor*	m_visitor;
                ILxUnknownID	m_tableauCtx;			// We need to store tableau context used to initialize listener
                                                                                                // NOTE: We need this, since tableau object that we get in the listener
                                                                                                //       is different than the tableau context object.
                                                                                                //       Also, we need tableau context to read channels values via GetChannels().
        };



        // Return instance
        static CLxTableauListener* GetInstance();

        // Constructor
        CLxTableauListener ();

        // Add item listener
        bool AddListener (
                                        ILxUnknownID				tableau,
                                        const TbxUpdateCallback&	callback,
                                        ILxUnknownID				item,
                                        int							chan);

        // Remove all listeners for given tableau
        void RemoveTableauListeners (
                                        ILxUnknownID	tableau);

        // Members
        typedef std::map < ILxUnknownID, ILxUnknownID >		TbxListenerMap;

        CLxPolymorph< Listener >	tli;
        TbxListenerMap				m_tbxListeners;
};


//-----------------------------------------------------------------------------
// Add tableau listener
//-----------------------------------------------------------------------------
        template< typename SourceT >
        inline bool
CLxTableauListener::Add (
        SourceT*		source,
        ILxUnknownID	tableau,
        ILxUnknownID	item,
        int				chanIndex)
{
        TbxUpdateCallback callback(source);

        return GetInstance ()->AddListener (tableau, callback, item, chanIndex);
}



#endif // LX_TABLEAU_HPP

