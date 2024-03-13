/*
 * LX thread module
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
#ifndef LX_thread_H
#define LX_thread_H

typedef struct vt_ILxWorkList ** ILxWorkListID;
typedef struct vt_ILxThreadMutex ** ILxThreadMutexID;
typedef struct vt_ILxThreadService ** ILxThreadServiceID;
typedef struct vt_ILxThreadJob ** ILxThreadJobID;
typedef struct vt_ILxThreadGroup ** ILxThreadGroupID;
typedef struct vt_ILxThreadSlot ** ILxThreadSlotID;
typedef struct vt_ILxThreadSlotClient ** ILxThreadSlotClientID;
typedef struct vt_ILxSharedWork ** ILxSharedWorkID;
typedef struct vt_ILxThreadRangeWorker ** ILxThreadRangeWorkerID;
typedef struct vt_ILxWaterfall ** ILxWaterfallID;

#include <lxcom.h>
        #include <stdlib.h>



/*
 * A worklist is a opaque container for units of work. Typically elements are processed
 * one at a time, and can be split into new spawned lists.
 */
typedef struct vt_ILxWorkList {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
IsEmpty) (
        LXtObjectID		 self);

        LXxMETHOD ( void *,
Next) (
        LXtObjectID		 self);

        LXxMETHOD ( LxResult,
Split) (
        LXtObjectID		 self,
        unsigned		 mode,
        void		       **ppvObj);

        LXxMETHOD ( void,
Clear) (
        LXtObjectID		 self);
} ILxWorkList;

/*
 * Mutexes are used for synchronization of threads. Only a single thread may be "in"
 * a mutex at a time.  And other thread calling Enter will block until the owning thread
 * has released the mutex with a Leave call.  NOTE: Calling Enter from a thread that 
 * already has the mutex will result in deadlock.
 * Critical sections are closely related to mutexes with the one (significant) difference
 * that a thread *can* re-enter a critical section it owns.  These are usually not 
 * necessary and have a greater performance cost than mutexes.  Critical sections 
 * share the THREADMUTEX interface.
 */
typedef struct vt_ILxThreadMutex {
        ILxUnknown	 iunk;
        LXxMETHOD ( void,
Enter) (
        LXtObjectID		 self);

        LXxMETHOD ( void,
Leave) (
        LXtObjectID		 self);
} ILxThreadMutex;

/*
 * The thread service allows you to create mutexes.
 * 
 * ... and critical sections.
 * 
 * The thread service interface allows new groups to be created.
 * 
 * There are also a couple of simple methods to determine the state of the
 * threading systems.
 * 
 * Finally this method allows allocating a new thread slot.
 * 
 * You start with a single one of these objects that contains all the work. You then
 * call the ProcesShared() method in the service. This will spawn enough of the shared
 * work objects to populate the available computing resources. Each one will then process
 * all the work it has, getting more from the main shared work object when they are
 * empty. When all the work is done the sub-objects are destroyed.
 * 
 * Multi-processing over a range of indices (such as scanlines in an image).
 * 
 * If a plugin creates its own threads, using some external library (like pthreads or OpenMP), 
 * it needs to initialize itself before it can call Nexus functions. This function allows that.
 * If the thread has already initialized itself, this function will do nothing.
 * 
 * Once the thread has finished executing Nexus code, it needs to free the Nexus specific thread-data,
 * so it must call CleanupThread, or there will be a memory leak.
 * 
 * This method takes a waterfall object and processes all the work it contains.
 * New instances will be spawned to fill out the given number of threads, or
 * one for each processor is the thread count is zero.
 * 
 * This section defines functions that are assurably atomic, meaning that there
 * are no possible race conditions if multiple threads call them on the same data
 * at once.
 * All values needs to be aligned to their size (i.e. 32-bit ints needs to be 32-bit aligned, and
 * 64-bit ints need to be 64-bit aligned). If they're not aligned, the functions do nothing.
 * All functions return the result of the increment or decrement.
 * 
 * These functions atomically increment and decrement an address-aligned integer.
 * 
 * 
 * These functions are the same but they allow you to add and subtract any number. They
 * return the result of the addition or subtraction.
 */
typedef struct vt_ILxThreadService {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
CreateMutex) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD ( LxResult,
CreateCS) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD ( LxResult, 
CreateGroup) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD ( unsigned int,
NumProcs) (
        LXtObjectID		 self);

        LXxMETHOD ( unsigned int,
IsMainThread) (
        LXtObjectID		 self);

        LXxMETHOD ( LxResult, 
CreateSlot) (
        LXtObjectID		 self,
        size_t			 size,
        LXtObjectID		 client,
        void			**ppvObj);
        LXxMETHOD ( LxResult, 
ProcessShared) (
        LXtObjectID		 self,
        LXtObjectID		 shared);

        LXxMETHOD ( LxResult,
ProcessRange) (
        LXtObjectID		 self,
        void			*data,
        int			 startIndex,
        int			 endIndex,
        LXtObjectID		 rangeWorker);
        LXxMETHOD ( LxResult,
InitThread) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
CleanupThread) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
ProcessWaterfall) (
        LXtObjectID		 self,
        LXtObjectID		 waterfall,
        unsigned		 threads);
        LXxMETHOD ( int,
AtomicIncrement) (
        LXtObjectID		 self,
        volatile int		*addr);

        LXxMETHOD ( int,
AtomicDecrement) (
        LXtObjectID		 self,
        volatile int		*addr);
        LXxMETHOD ( int,
AtomicIntegerAdd) (
        LXtObjectID		 self,
        volatile int		*addr,
        int			 val);

        LXxMETHOD ( int,
AtomicIntegerSubtract) (
        LXtObjectID		 self,
        volatile int		*addr,
        int			 val);
} ILxThreadService;

/*
 * Clients specify the work they wish to perform by creating a Job.  The job
 * is a very simple object that has a single method - Execute.  Jobs can be added
 * to other ThreadService objects which can in turn control their threaded 
 * execution.
 */
typedef struct vt_ILxThreadJob {
        ILxUnknown	 iunk;
        LXxMETHOD ( void,
Execute) (
        LXtObjectID		 self);
} ILxThreadJob;

/*
 * A more useful higher level construct than the Job is the thread group.  Thread
 * Groups allow the client launch several threads at once.  Each thread in the group 
 * gets its own ThreadFunc and data.  Usually, all the threads in the group will have
 * the same ThreadFunc but different pieces of data.  They may run either synchronously or 
 * asynchronously.
 */
typedef struct vt_ILxThreadGroup {
        ILxUnknown	 iunk;
        LXxMETHOD ( void,
AddJob) (
        LXtObjectID		 self,
        LXtObjectID		 job);
        
        LXxMETHOD ( unsigned,
NumJobs) (
        LXtObjectID		 self);
        
        LXxMETHOD ( void,
Clear) (
        LXtObjectID		 self);
        
        LXxMETHOD ( void,
Execute) (
        LXtObjectID		 self);
        
        LXxMETHOD ( void,
Wait) (
        LXtObjectID		 self);
        
        LXxMETHOD ( LxResult,
Running) (
        LXtObjectID		 self);
        
        LXxMETHOD ( void,
Kill) (
        LXtObjectID		 self);
} ILxThreadGroup;

/*
 * Slots are a way to store data locally for each thread.
 */
typedef struct vt_ILxThreadSlot {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
Set) (
        LXtObjectID		 self,
        void			*value);

        LXxMETHOD ( LxResult,
Get) (
        LXtObjectID		 self,
        void		       **value);

        LXxMETHOD ( LxResult,
Clear) (
        LXtObjectID		 self);
} ILxThreadSlot;

/*
 * Defining a slot can use a client class for allocating and freeing the data.
 */
typedef struct vt_ILxThreadSlotClient {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
Alloc) (
        LXtObjectID		 self,
        void		       **value);

        LXxMETHOD ( LxResult,
Free) (
        LXtObjectID		 self,
        void			*value);
} ILxThreadSlotClient;

/*
 * Shared work represents a batch of work that can be done in parallel.
 * - Evaluate
 * Process one unit of work and return a result code. An error will terminate the whole
 * process. If there is no more work left to do return LXe_FALSE.
 * - Spawn
 * Create a new shared work object of the same type. The new object should have no work.
 * 
 * - Share
 * Move work from this object to the other. This is typically only one unit of work, but
 * if the work units are especially small, more than one at a time can be moved to reduce
 * contention. When there is no work left return LXe_FALSE.
 * 
 */
typedef struct vt_ILxSharedWork {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
Evaluate) (
        LXtObjectID		 self);

        LXxMETHOD ( LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD ( LxResult,
Share) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        unsigned int		 split);
} ILxSharedWork;

/*
 * A range worker performs processing over a range of indices (such as scanlines in an image).
 */
typedef struct vt_ILxThreadRangeWorker {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
Execute) (
        LXtObjectID		 self,
        int			 index,
        void			*sharedData);
} ILxThreadRangeWorker;

/*
 * Spawn() creates a new waterfall object taking the first work in the current
 * stage. If there's no more work in this stage this should fail.
 * 
 * Query the state of the waterfall object. This returns one of the LXiWFALL
 * state values.
 * - DONE
 * indicates that the last work in the last stage has been completed.
 * 
 * - HASWORK
 * means that this waterfall object has work ready to be processed.
 * 
 * - NEXT_WORK, NEXT_STAGE
 * if the waterfall object has no work it can indicate that there is more work
 * in this stage, or that the current stage is complete but there is more work
 * in the next stage.
 * 
 * 
 * If this object has work loaded it can be discharged with this method. This is
 * the only method that will be called concurrently; all other methods will be
 * called in one thread at a time and so don't need to protect themselves.
 * 
 * If there is work available in the current stage this is used to take one
 * unit of work and load it into this object.
 * 
 * If there is no work in the current stage this is called to advance the 
 * waterfall to the next stage. All the work in the previous stage will have
 * been completely processed.
 */
typedef struct vt_ILxWaterfall {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD ( unsigned,
State) (
        LXtObjectID		 self);
        LXxMETHOD ( LxResult,
ProcessWork) (
        LXtObjectID		 self);
        LXxMETHOD ( LxResult,
GetWork) (
        LXtObjectID		 self);
        LXxMETHOD ( LxResult,
Advance) (
        LXtObjectID		 self);
} ILxWaterfall;


        #define LXi_SIMD_MAXRUN	 512

/*
 * ILxThreadService service provides a simple interface into basic threading constructs
 * and, more importantly, a way to synchronize with the host process and other threads.
 */

        #define LXu_THREADSERVICE	"0A9D5B42-1DA6-42A4-8FC4-01FCCE939AC4"
        #define LXa_THREADSERVICE	"threadservice"
        // [python] ILxThreadService:CreateCS		obj ThreadMutex
        // [python] ILxThreadService:CreateMutex	obj ThreadMutex
        // [python] ILxThreadService:CreateGroup	obj ThreadGroup
        // [python] ILxThreadService:CreateSlot		obj ThreadSlot
        // [const]  ILxThreadService:InitThread
        // [const]  ILxThreadService:CleanupThread

        #define LXu_THREADMUTEX		"7624F6B7-83FD-424F-A68E-0EDD089167CB"
        #define LXa_THREADMUTEX		"threadmutex"
        // [local]  ILxThreadMutex 

        #define LXu_THREADJOB		"DE892B0B-A791-4FA5-B85D-46E8CACB695B"
        #define LXa_THREADJOB		"threadjob"
        // [local]  ILxThreadJob
        // [export] ILxThreadJob job

        #define LXu_THREADGROUP		"54A9DD48-3AFC-435F-9F17-2EEB6FB46FBA"
        #define LXa_THREADGROUP		"threadgroup"
        // [local]  ILxThreadGroup
        // [python] ILxThreadGroup:Running	bool

        #define LXu_WORKLIST		"74568CA9-92C9-4C73-9851-E9169934629A"
        #define LXa_WORKLIST		"worklist"
        // [local]  ILxWorkList
        // [export] ILxWorkList work
        // [python] ILxWorkList:Split	obj WorkList
        // [python] ILxWorkList:IsEmpty	bool

        #define LXu_THREADSLOT		"365E4616-0FB9-478E-993D-D35282F4C326"
        // [local]  ILxThreadSlot

        #define LXu_THREADSLOTCLIENT	"D24835B6-518B-4E33-8A70-E53038C29BB7"
        // [local]  ILxThreadSlotClient
        // [export] ILxThreadSlotClient tsc

        #define LXu_SHAREDWORK		"4D414F97-35A4-4B26-84FE-0E740C79722C"
        // [local]  ILxSharedWork
        // [export] ILxSharedWork share
        // [python] ILxSharedWork:Spawn		obj SharedWork

        #define LXu_THREADRANGEWORKER	"612153FE-572F-4CD6-8033-B905762C3106"
        #define LXa_THREADRANGEWORKER	"threadrangeworker"
        // [local] ILxThreadRangeWorker
        // [export] ILxThreadRangeWorker rngw


        #define LXiWLSPLIT_NONE	 0
        #define LXiWLSPLIT_ONE	 1
        #define LXiWLSPLIT_HALF	 2

/*
 * A waterfall is a model of threaded computation that combines parallel and
 * sequential elements. The metaphor is of a waterfall consisting of a set of
 * pools at different levels. Water fills the first set of pools in parallel,
 * but the pools at the next level don't start to fill until the first level
 * is completely full.
 * Likewise the waterfall object presents a parade of work units in stages. The
 * work at each stage has to be complete before the next stage can begin. The
 * object manages not only the work list but the processing, which it does by
 * allowing multiple copies of itself to work on the same list.
 */

        #define LXu_WATERFALL		"2B845B2A-06BE-4C90-8E50-58F7FBEEC25E"
        #define LXa_WATERFALL		"waterfall"
        // [local]  ILxWaterfall
        // [export] ILxWaterfall wfall
        // [python] ILxWaterfall:Spawn		obj Waterfall

        #define LXiWFALL_DONE		 0
        #define LXiWFALL_HASWORK	 1
        #define LXiWFALL_NEXT_WORK	 2
        #define LXiWFALL_NEXT_STAGE	 3

#endif
