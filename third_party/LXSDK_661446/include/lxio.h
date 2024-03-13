/*
 * LX io module
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
 */
#ifndef LX_io_H
#define LX_io_H

typedef struct vt_ILxBlockRead ** ILxBlockReadID;
typedef struct vt_ILxBlockWrite ** ILxBlockWriteID;
typedef struct vt_ILxLoader ** ILxLoaderID;
typedef struct vt_ILxLoaderInfo ** ILxLoaderInfoID;
typedef struct vt_ILxSaver ** ILxSaverID;
typedef struct vt_ILxMonitor ** ILxMonitorID;
typedef struct vt_ILxStreamIO ** ILxStreamIOID;
typedef struct vt_ILxIOService ** ILxIOServiceID;
typedef struct vt_ILxBlockStore ** ILxBlockStoreID;
typedef struct vt_ILxLoader1 ** ILxLoader1ID;

#include <lxcom.h>
#include <lxvalue.h>
        #include <stdlib.h>

/*
 * Bookmarks allow blocks in the file to be referenced by an ID. The client is
 * expected to allocate bookmark pointers which can be used to store and restore
 * block locations, or to specify root locations for sub-blocks. The bookmarks 
 * are all freed when the file is closed.
 */

        typedef struct st_BlockBookmark * LXtBlockBookmarkID;
        // [python] type LXtBlockBookmarkID	id


/*
 * Block streams are also style-transparent, reading and writing using the
 * same API for both text and binary streams.  As result, blocks have to be
 * identified by both a binary ID code and a text string.  Internally, the
 * binary ID code value is always used.
 */
typedef struct st_LXtBlockHeader {
        LXtID4			 id;
        const char		*token;
} LXtBlockHeader;

typedef struct st_LXtLoadAccess1 {
        const char		*filename;
        const LXtGUID	       **types;
        LXtObjectID		 monitor;
        const LXtGUID		*found;
        int			 opaque;
        void			*target;
        const char		*format;
        int			 options;
} LXtLoadAccess1;


/*
 * Function descriptions are not provided since these objects are not
 * commonly encountered in nexus file I/O.  TODO: fill these in.
 * 
 * Reading a string takes a buffer for the result and its size. If FORCE is true
 * this will return an error if no string is found. If PARTIAL is true then as much
 * string as can be found will be read into the buffer and LXe_IO_PARTIALSTRING
 * will be returned if there is more left to read. Otherwise the entire string will
 * always be read and LXe_IO_TRUNCATED will be returned if some of the string had to
 * be discarded. The returned count is the number of characters read including the
 * terminating null.
 * 
 * 
 * ReadString converts a text encoding of string to another text encoding given by
 * the following methods using ILxTextEncoding service. The source encoding is the
 * encoding for strings to read. The target encoding is for a string set to "buf"
 * of ReadString. The text encoding convertion does not work with PARTIAL mode.
 * The returned count is the number of characters read including the terminating
 * null based on the source string.
 */
typedef struct vt_ILxBlockRead {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
FindBlock) (
        LXtObjectID		 self,
        const LXtBlockHeader	*head,
        int			 flags,
        LXtID4			*blkId);

        LXxMETHOD( void,
End) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Depth) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
ReadI1) (
        LXtObjectID		 self,
        char			*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadI2) (
        LXtObjectID		 self,
        short			*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadI4) (
        LXtObjectID		 self,
        int			*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadU1) (
        LXtObjectID		 self,
        unsigned char		*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadU2) (
        LXtObjectID		 self,
        unsigned short		*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadU4) (
        LXtObjectID		 self,
        unsigned int		*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadFP) (
        LXtObjectID		 self,
        float			*data,
        int			 count,
        int			*ocount);

        LXxMETHOD( LxResult,
ReadFP8) (
        LXtObjectID		 self,
        double			*data,
        int			 count,
        int			*ocount);
        LXxMETHOD( LxResult,
ReadString) (
        LXtObjectID		 self,
        char			*buf,
        int			 max,
        int			 flags,
        int			*ocount);
        LXxMETHOD( LxResult,
ReadIDCode) (
        LXtObjectID		 self,
        const LXtBlockHeader	*list,
        LXtID4			*idCode);

        LXxMETHOD( LxResult,
ReadVX) (
        LXtObjectID		 self,
        unsigned		*data,
        int			 count,
        int			*ocount);
        LXxMETHOD(  LxResult,
SetSourceEncoding) (
        LXtObjectID		 self,
        unsigned		 encoding);

        LXxMETHOD(  LxResult,
SetTargetEncoding) (
        LXtObjectID		 self,
        unsigned		 encoding);

        LXxMETHOD(  LxResult,
SetMiniBlockHeight) (
        LXtObjectID		 self,
        unsigned		 mini);
} ILxBlockRead;

/*
 * 
 * WriteString converts a text encoding of string to another text encoding given by
 * the following methods using ILxTextEncoding service. The source encoding is for
 * a string set to "buf" of WriteString.  The target encoding is the encoding for
 * strings to write.
 */
typedef struct vt_ILxBlockWrite {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
WriteBlock) (
        LXtObjectID		 self,
        const LXtBlockHeader	*head,
        int			 flags);

        LXxMETHOD( void,
End) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Depth) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
WriteI1) (
        LXtObjectID		 self,
        const char		*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteI2) (
        LXtObjectID		 self,
        const short		*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteI4) (
        LXtObjectID		 self,
        const int		*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteU1) (
        LXtObjectID		 self,
        const unsigned char	*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteU2) (
        LXtObjectID		 self,
        const unsigned short	*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteU4) (
        LXtObjectID		 self,
        const unsigned int	*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteFP) (
        LXtObjectID		 self,
        const float		*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteFP8) (
        LXtObjectID		 self,
        const double		*data,
        int			 count);

        LXxMETHOD( LxResult,
WriteString) (
        LXtObjectID		 self,
        const char		*str);

        LXxMETHOD( LxResult,
WriteIDCode) (
        LXtObjectID		 self,
        const LXtBlockHeader	*ident);

        LXxMETHOD( LxResult,
WriteVX) (
        LXtObjectID		 self,
        const unsigned int	*data,
        int			 count);
        LXxMETHOD(  LxResult,
SetSourceEncoding) (
        LXtObjectID		 self,
        unsigned		 encoding);

        LXxMETHOD(  LxResult,
SetTargetEncoding) (
        LXtObjectID		 self,
        unsigned		 encoding);
} ILxBlockWrite;

/*
 * An ILxLoader interface is an extensible server for loading objects of
 * many different classes. Methods on the loader interface are called in sequence.
 * Specifically Recognize() is called to open a file, and Cleanup() is called to
 * close it. Recognize() is given the filename and LoadInfo object, and it should
 * return OK if the file can be loaded by this loader.
 * 
 * The loader can also set other data by querying for additional interfaces based
 * on object type. This is useful when doing a direct load to specify the attributes
 * of the object to contain the data. For instance to do a direct load of an image
 * the loader would query for ImageLoaderTarget and use its methods to set the
 * pixel format and size of the destination image. The LoadInfo object can also be
 * queried for a monitor.
 * After recognition, the LoadInstance() method may be called to load opaque
 * objects, in which case the new COM object should be returned in the void
 * pointer. For non-opaque loads the (perhaps confusingly named) LoadObject()
 * method may be called to load the data into the destination object.
 * 
 * 
 * After any attempt at recognition Cleanup() will be called to allow the loader
 * to close the file and reset its state.
 * 
 * This method creates an option object for this loader. This should have a StreamIO
 * interface to allow it to be saved and loaded.
 */
typedef struct vt_ILxLoader {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		 self,
        const char		*filename,
        LXtObjectID		 loadInfo);
        LXxMETHOD( LxResult,
LoadInstance) (
        LXtObjectID		 self,
        LXtObjectID		 loadInfo,
        LXtObjectID		 monitor,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
LoadObject) (
        LXtObjectID		 self,
        LXtObjectID		 loadInfo,
        LXtObjectID		 monitor,
        LXtObjectID		 dest);
        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SpawnOptions) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxLoader;

/*
 * The LoaderInfo interface can be used to read the context of the load and to
 * set the attributes that apply to this file. For loaders that can load more than
 * one object type, TestClass() returns LXe_TRUE for classes that the client wants
 * to accept. The priority for each type can be used to decide which one to accept,
 * where lower is better.
 * 
 * During recognition the loader can set information about a file that it's capable
 * of loading. All of this is optional. The class is the object type for loaders
 * that can load more than one type. Flags can suggest opaque versus direct load
 * and if the format has options. The format can be set if a different saver should
 * be used for this object type.
 */
typedef struct vt_ILxLoaderInfo {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
TestClass) (
        LXtObjectID		 self,
        const LXtGUID		*clsGUID,
        unsigned		*priority);
        LXxMETHOD( LxResult,
SetClass) (
        LXtObjectID		 self,
        const LXtGUID		*clsGUID);

        LXxMETHOD( LxResult,
SetFlags) (
        LXtObjectID		 self,
        unsigned		 flags);

        LXxMETHOD( LxResult,
SetFormat) (
        LXtObjectID		 self,
        const char		*format);
} ILxLoaderInfo;

/*
 * An ILxSaver interface knows how to save objects of a specific type.  This
 * is a very much simpler interface and just has a single function to
 * perform the save to the given file using the given monitor.  The Verify method
 * allows the plugin to inform the user if parts of his scene will not
 * be saved.  The source is the object being saved.
 */
typedef struct vt_ILxSaver {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Verify) (
        LXtObjectID		 self,
        LXtObjectID		 source,
        LXtObjectID		 message);

        LXxMETHOD( LxResult,
Save) (
        LXtObjectID		 self,
        LXtObjectID		 source,
        const char		*filename,
        LXtObjectID		 monitor);
} ILxSaver;

/*
 * An ILxMonitor interface allows progress tracking.  The monitor is initialized with
 * a max count, and each stage of processing increments the count by something.
 * Initialize() takes the total number of steps the monitor has, and returns a result
 * code.  It is possible that the monitor will be immediately aborted, so you should
 * check for LXe_ABORT codes from this call.
 * 
 * 
 * This steps the monitor by the count provided.  Care should be taken to keep from
 * exceeding the total number of steps set with Initialize().  Of the user has aborted
 * the operation, this method will return LXe_ABORT and the client should stop the
 * operation.  Commands normally set the LXe_ABORT code on their message object so
 * that the caller knows that the command has been aborted by the user.
 */
typedef struct vt_ILxMonitor {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        unsigned int		 count);
        LXxMETHOD( LxResult,
Increment) (
        LXtObjectID		 self,
        unsigned int		 count);
} ILxMonitor;

/*
 * An ILxStreamIO interface allows any object to save or load itself on a block
 * stream.  The Write() method writes the underlying object to the block
 * stream, while the Read() method reads the data and sets the state of the
 * object to match the one that was written.  The caller will have determined
 * that an object of the right type follows in the stream.
 */
typedef struct vt_ILxStreamIO {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Write) (
        LXtObjectID		 self,
        LXtObjectID		 stream);

        LXxMETHOD( LxResult,
Read) (
        LXtObjectID		 self,
        LXtObjectID		 stream);
} ILxStreamIO;

/*
 * 
 * These methods are used to access the global load-options object. This is an
 * object set by the loader's options command which can then be read by the loader
 * during the actual load. It will also be stored in the case of sub-object loads.
 * 
 * Open a block store. Each store has a format given by a string up to 8 charaters
 * in length. Depending on the flags the file may be created if it doesn't exist, in
 * which case this method returns FALSE instead of OK.
 */
typedef struct vt_ILxIOService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
SetOptions) (
        LXtObjectID		 self,
        LXtObjectID		 options);

        LXxMETHOD( LXtObjectID,
PeekOptions) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
OpenBlockStore) (
        LXtObjectID		 self,
        const char		*filename,
        const char		*format,
        unsigned		 flags,
        void		       **ppvObj);
} ILxIOService;

/*
 * 
 * The main function of the interface is to set the current block. This can be done
 * by finding a block by type and id code. This returns LXe_TRUE for an existing block,
 * and FALSE for a block that doesn't exist. If the parent is null this will look for
 * root blocks, otherwise it will search for sub-blocks of the parent block. The user
 * class version of the method makes it optional.
 * 
 * It can be useful when traversing a block store to set the current location as the
 * new root, so that subsequent lookup occur in that context. That can be done by
 * pushing it onto the location stack. The stack can be popped when done or cleared
 * to reset searches back to the root.
 * 
 * You can also enumerate blocks by type. The Count() returns the number of blocks of
 * that type, and ByIndex() sets the current block. Parent determines whether these
 * are root or sub-blocks.
 * 
 * Or, of course, the current location can be set using a bookmark.
 * 
 * Once the current block is set a location can be remembered to bookmark this spot.
 * 
 * Properties of the current block can be read.
 * 
 * The current block can also be deleted. This also deletes any sub-blocks.
 * 
 * The BlockRead and BlockWrite interfaces on the store object are convenient for
 * writing structured data, but they do use intermediate memory and so may not
 * be as fast or efficient as possible. As an alternative writing and reading can
 * be done directly to and from the block store file.
 * To write a new block or to resize and exisitng block this function can be used.
 * The space will be allocated for the data in the file, but its contents are 
 * undefined. To set the contents of the block the next function should be used.
 * 
 * 
 * If the current block is writable, this function will write a given number of
 * raw bytes from the buffer into the file at a position offset from the start 
 * of the block.
 * 
 * Likewise for a readable block this function will read raw bytes into the buffer
 * from the given position and size in the block.
 */
typedef struct vt_ILxBlockStore {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
AllocBookmark) (
        LXtObjectID		 self,
        LXtBlockBookmarkID	*loc);
        LXxMETHOD( LxResult,
Lookup) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*id,
        LXtBlockBookmarkID	 parent);
        LXxMETHOD( LxResult,
Stack) (
        LXtObjectID		 self,
        unsigned		 operation);
        LXxMETHOD( LxResult,
Count) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned		*count,
        LXtBlockBookmarkID	 parent);

        LXxMETHOD( LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned		 index,
        LXtBlockBookmarkID	 parent);
        LXxMETHOD( LxResult,
RestoreBookmark) (
        LXtObjectID		 self,
        LXtBlockBookmarkID	 loc);
        LXxMETHOD( LxResult,
SaveBookmark) (
        LXtObjectID		 self,
        LXtBlockBookmarkID	 loc);
        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        LXtID4			*type);

        LXxMETHOD( LxResult,
Ident) (
        LXtObjectID		 self,
        const char	       **id);

        LXxMETHOD( LxResult,
Size) (
        LXtObjectID		 self,
        size_t			*size);
        LXxMETHOD( LxResult,
Delete) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
WriteSize) (
        LXtObjectID		 self,
        size_t			 size);
        LXxMETHOD( LxResult,
WriteBlock) (
        LXtObjectID		 self,
        const void		*buf,
        size_t			 offset,
        size_t			 size);
        LXxMETHOD( LxResult,
ReadBlock) (
        LXtObjectID		 self,
        void			*buf,
        size_t			 offset,
        size_t			 size);
} ILxBlockStore;

typedef struct vt_ILxLoader1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		 self,
        LXtLoadAccess1		*load);

        LXxMETHOD( LxResult,
LoadInstance) (
        LXtObjectID		 self,
        LXtLoadAccess1		*load,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
LoadObject) (
        LXtObjectID		 self,
        LXtLoadAccess1		*load,
        LXtObjectID		 dest);

        LXxMETHOD( LxResult,
Cleanup) (
        LXtObjectID		 self,
        LXtLoadAccess1		*load);

        LXxMETHOD( LxResult,
SpawnOptions) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxLoader1;

/*
 * Writing block files is pretty simple. There is a stack which represents the
 * levels of block nesting. Each stack entry points to a block header with the
 * position and size of the block for deferred writing. A block does
 * not count the length of any block higher in the stack until those blocks
 * have been closed.  Flags bits are used by the save state API.
 */

#define Int64 MCtINT_PTR

/*
 * These are error codes for this subsystem and all other I/O-related subsystems.
 */

        #define LXe_IO_ERROR		LXxFAILCODE(LXeSYS_IO,1)
        #define LXe_REF_BADID		LXxFAILCODE(LXeSYS_IO,22)
        #define LXe_REF_BADPTR		LXxFAILCODE(LXeSYS_IO,23)
        #define LXe_REF_DUPLICATE	LXxFAILCODE(LXeSYS_IO,24)
        #define LXe_IO_SHORTREAD	LXxFAILCODE(LXeSYS_IO,25)
        #define LXe_IO_NEEDGL		LXxFAILCODE(LXeSYS_IO,26)
        #define LXe_IO_TRUNCATED	LXxGOODCODE(LXeSYS_IO,27)
        #define LXe_IO_PARTIALSTRING	LXxGOODCODE(LXeSYS_IO,28)

/*
 * Block stream interfaces support block-structured I/O with multiple data
 * types.  There is an interface for reading and one for writing.
 */

        #define LXu_BLOCKREAD		"36A00A47-2664-49E0-BAFF-263E638532B5"
        #define LXu_BLOCKWRITE		"ADE569E1-E9A1-4AD6-B625-634093660965"
        // [local]  ILxBlockRead
        // [local]  ILxBlockWrite

/*
 * For string reading, there are two modes - FORCE and RAW.  Force will
 * raise an exception if the string is not found.  If not set, however, the
 * function will return true if any string is read, including the empty
 * string.  RAW causes the stream to be read as a literal string, ignoring
 * quotes and reading to eol.
 */

        #define	LXfBLKS_FORCE	 (1<<0)
        #define	LXfBLKS_RAW	 (1<<1)


        // [python] ILxBlockRead:ReadI4:data	vector (count)


        #define	LXfREADSTRING_FORCE	0x01
        #define	LXfREADSTRING_RAW	0x02
        #define	LXfREADSTRING_PARTIAL	0x04

/*
 * The write methods are very similar to the read methods.
 * Function descriptions are not provided since these objects are not
 * commonly encountered in nexus file I/O.  TODO: fill these in.
 * LEAF blocks can contain no sub-blocks.  PARAM blocks are leaf blocks written
 * at the start of a non-leaf block.  In XML they are written into the block
 * header, but otherwise are identical to normal blocks.
 */

        #define LXfBLKW_LEAF	 (1<<0)
        #define LXfBLKW_PARAM	 (1<<1)


        #define LXfLOAD_OPAQUE		 0x01
        #define LXfLOAD_OPTIONS		 0x02


        #define LXu_LOADERINFO	"4CA8BE1A-6ADE-4F93-99F6-1F0EFC8A581E"
        #define LXa_LOADERINFO	"loaderinfo"
        // [export] ILxLoaderInfo linf
        // [local]  ILxLoaderInfo

        #define LXu_LOADER	"7711F608-B8FF-48BF-81ED-CEBDE54D34DE"
        #define LXa_LOADER	"loader2"
        // [export] ILxLoader
        // [local]  ILxLoader
        // [python] ILxLoader:SpawnOptions	obj Unknown
        // [python] ILxLoader:LoadInstance	obj Unknown

/*
 * Tags define the classes this loader server supports and hints about the files
 * that it might be able to process.
 * - CLASSLIST
 * a string of class aliases or GUIDs separated by spaces, such as "image
 * animation".  These are the classes which this loader can support.
 * - DOSPATTERN
 * a pattern string for filenames in Microsoft Windows (really DOS) format.
 * This is typically something like "*.avi;*.jpg".
 * 
 * - MACPATTERN
 * a pattern string for Macintosh filetypes that might be read with this
 * loader.  This is typically something like "MooV;TTXT".
 * 
 * - THREADSAFE
 * indicates whether the loader is threadsafe (i.e. multiple loaders of the
 * same type can be executed at once). Values other than "Yes" are all interpreted
 * as no.
 * 
 */

        #define LXsLOD_CLASSLIST	"loader.classList"
        #define LXsLOD_DOSPATTERN	"loader.dosPattern"
        #define LXsLOD_MACPATTERN	"loader.macPattern"
        #define LXsLOD_THREADSAFE	"loader.threadsafe"

/*
 * One general class GUID for loaders is the "side-effect" object class. A loader
 * which loads a side-effect object doesn't really load anything, it just wants a
 * chance to parse a file and do something. There is no ILxSideEffect interface.
 */

        #define LXu_SIDEEFFECT	"3414D56B-31DE-47C7-B751-092B51591DD2"
        #define LXa_SIDEEFFECT	"sideeffect"


        #define LXu_SAVER	"75AD8F36-5B69-413b-A77B-5A78D39AEF51"
        #define LXa_SAVER	"saver"
        // [export] ILxSaver
        // [local]  ILxSaver

/*
 * Tags define the single class and file type.
 * - OUTCLASS
 * the class alias or GUID for objects that can be saved. ("image")
 * - DOSTYPE
 * the three-character DOS file extension that should be used by default.
 * ("JPG")
 * 
 * - MACTYPE
 * the four-character Macintosh type code that should be applied to the
 * new file.  ("PICT")
 * 
 * - OVERWRITE
 * indicates that the saver needs to original file in place in order to save
 * changes into it. This disables any safety mechanism that renames the original
 * file to prevent save errors from destroying data. Savers that set this tag to
 * "1" are expected to handle save errors gracefully on their own.
 * 
 * - SAVEAS
 * indicates that the saver can be used in the Save As dialog. Save As will allow
 * only savers that have appropriate loader to be listed and it's comparing saver
 * and loader by using server name. If you have named loader and saver for the same
 * file format differently, then you can use this flag in order to get your saver
 * to be displayed in the Save As dialog.
 * 
 */

        #define LXsSAV_OUTCLASS		"saver.outClass"
        #define LXsSAV_DOSTYPE		"saver.dosType"
        #define LXsSAV_MACTYPE		"saver.macType"
        #define LXsSAV_OVERWRITE	"saver.overwrite"
        #define LXsSAV_SAVEAS		"saver.saveAs"

/*
 * These macros support calling the function vectors on monitor objects.  If the
 * monitor pointer is null, these do no harm.  Init returns zero on failure and
 * incr/step returns zero to continue.  The Increment() method can be called
 * directly to determine if it returned a failure code or LXe_ABORT.
 * The most useful macros here are:
 * - INIT()
 * Returns true if the monitor was successfully initialized.  This may return false
 * to indicate that that the monitor was aborted as soon as it was opened, usually
 * because it wound up being a sub-monitor of another monitor.
 * 
 * - INCR()
 * Increment a monitor by the given number of steps.  Returns true if the user aborted,
 * and false if it is still running.
 * 
 * - STEP()
 * Increment the monitor by one step.  Returns true if the user aborted.
 * 
 * - TEST()
 * Returns true if the user aborted, and false if it is still running.  Under the hood,
 * this is simply calling INCR() with a step of 0, and will check for user input before
 * returning.  If you are running a long but unbounded task where you can't step the
 * monitor, this will allow you to check for aborts without the app appearing to be
 * locked.
 * 
 * - STATUS()
 * Same as TEST(), but returns an LxResult code of LXe_ABORT if the user aborted, and
 * LXe_OK if the monitor is still running.
 * 
 */

        #define LXu_MONITOR		"2B514D4C-5142-4687-BCEF-B0FD44A33146"
        #define LXa_MONITOR		"monitor"
        // [export] ILxMonitor
        // [local]  ILxMonitor
        // [python] ILxMonitor:Increment	global

        #define LXxMON_CALL(m,fn,k)	((m[0]->fn)(m,k))
        #define LXxMON_OCAL(m,fn,k)	(m ? LXxMON_CALL(m,fn,k) : LXe_OK)

        #define LXxMON_INIT(m,n)	LXx_OK  (LXxMON_OCAL(m,Initialize,n))
        #define LXxMON_INCR(m,i)	LXx_FAIL(LXxMON_OCAL(m,Increment, i))
        #define LXxMON_STEP(m)		LXxMON_INCR(m,1)
        #define LXxMON_TEST(m)		LXxMON_INCR(m,0)
        #define LXxMON_STATUS(m)	LXxMON_OCAL(m,Increment, 0)


        #define LXu_STREAMIO	"2884D6EE-4BA7-46D6-A776-8EE22C9FD414"
        // [export] ILxStreamIO io
        // [local]  ILxStreamIO

/*
 * We provide some global IO services.
 */

        #define LXu_IOSERVICE	"9970CCAD-7322-4CD6-A6BA-963A63DE57D7"
        #define LXa_IOSERVICE	"ioservice"
        // [python] ILxIOService:OpenBlockStore bool
        // [python] ILxIOService:OpenBlockStore obj BlockStore

/*
 * It can be useful to store data in a format that allows blocks to be randomly
 * accessed. The indexed block store is a format where blocks are given by type and
 * name, and the blocks can be read or written in any sequence. The block store
 * object presents the main BlockStore interface, as well as BlockRead and BlockWrite
 * interfaces for access the contents of blocks using a serial block structure.
 * Blocks are hierarchical, so blocks can contain sub-blocks which can also be
 * accessed randomly.
 */

        #define LXu_BLOCKSTORE	"9094E95E-E91E-42AE-ABD6-8426CC0AE42A"
        // [local]  ILxBlockStore


        #define	LXiOBS_PUSH	 0
        #define	LXiOBS_POP	 1
        #define	LXiOBS_CLEAR	 2

/*
 * Files are normally opened for read unless the flags specify otherwise.
 * - WRITE
 * Opens the file for write. If the file doesn't exist it will be created and
 * if it does exist it will be cleared.
 * - MODIFY
 * Same as WRITE, except that if the file already exists it won't be cleared
 * and its existing contents can be altered.
 * 
 * - MUSTEXIST
 * If this flag is set then the method will raise an error if the file can't
 * be found.
 * 
 */

        #define	LXfOBS_WRITE	 0x01
        #define	LXfOBS_MODIFY	 0x02
        #define	LXfOBS_MUSTEXIST 0x04


        #define LXu_LOADER1	"73333A41-3C0A-4B0E-A7C5-D76609827A2D"
        #define LXa_LOADER1	"loader"
        // [export] ILxLoader1

#endif
