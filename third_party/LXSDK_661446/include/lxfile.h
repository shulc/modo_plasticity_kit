/*
 * LX file module
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
#ifndef LX_file_H
#define LX_file_H

typedef struct vt_ILxFile1Service ** ILxFile1ServiceID;
typedef struct vt_ILxVirtualDevice ** ILxVirtualDeviceID;
typedef struct vt_ILxFileService ** ILxFileServiceID;
typedef struct vt_ILxFileReference ** ILxFileReferenceID;
typedef struct vt_ILxFileRedirect ** ILxFileRedirectID;

#include <lxcom.h>



typedef struct vt_ILxFile1Service {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
FileSystemPath) (
        LXtObjectID               self,
        const char               *name,
        const char              **path);

        LXxMETHOD(  const char *,
FileSystemDefaultIO) (
        LXtObjectID              self,
        int                      isForLoad);

        LXxMETHOD(  LxResult,
IsAbsolutePath) (
        LXtObjectID              self,
        const char              *path);

        LXxMETHOD(  LxResult,
ArePathsEqual) (
        LXtObjectID              self,
        const char              *path1,
        const char              *path2);

        LXxMETHOD(  LxResult,
ParsePath) (
        LXtObjectID              self,
        const char              *filename,
        char                    *basename,
        char                    *path);

        LXxMETHOD(  LxResult,
ComposePath) (
        LXtObjectID              self,
        char                    *filename,
        const char              *basename,
        const char              *path);

        LXxMETHOD(  LxResult,
MakeRelative) (
        LXtObjectID              self,
        char                    *relname,
        const char              *filename,
        const char              *path);

        LXxMETHOD(  LxResult,
MakeUnique) (
        LXtObjectID              self,
        char                    *filename);

        LXxMETHOD(  LxResult,
FindExtension) (
        LXtObjectID              self,
        const char              *path,
        const char             **extension);

        LXxMETHOD(  LxResult,
SetExtension) (
        LXtObjectID              self,
        char                    *path,
        const char              *extension);

        LXxMETHOD(  LxResult,
MakeDirectory) (
        LXtObjectID               self,
        const char               *path);

        LXxMETHOD(  LxResult,
TestFileType) (
        LXtObjectID              self,
        const char              *filename,
        int                     *type);

        LXxMETHOD(  LxResult,
TestFileMode) (
        LXtObjectID              self,
        const char              *filename,
        int                     *mode);

        LXxMETHOD(  LxResult,
RenameFile) (
        LXtObjectID              self,
        const char              *from,
        const char              *to);

        LXxMETHOD(  LxResult,
FileCopy) (
        LXtObjectID              self,
        const char              *srcFilePath,
        const char              *dstFilePath,
        int                      overwrite);

        LXxMETHOD(  LxResult,
FileDelete) (
        LXtObjectID              self,
        const char              *filename);

        LXxMETHOD(  LxResult,
DirDelete) (
        LXtObjectID              self,
        const char              *filename);

        LXxMETHOD(  LxResult,
OpenFileWithDefaultApp) (
        LXtObjectID              self,
        const char              *filename);

        LXxMETHOD(  LxResult,
RevealInFileViewer) (
        LXtObjectID              self,
        const char              *filename);

        LXxMETHOD(  LxResult,
Execute) (
        LXtObjectID              self,
        const char              **argv,
        int                       show,
        int                       force32);

        LXxMETHOD(  LxResult,
FileToURL) (
        LXtObjectID              self,
        const char              *filename,
        char                    *buf,
        unsigned                 len);

        LXxMETHOD(  LxResult,
FileFromURL) (
        LXtObjectID              self,
        const char              *url,
        char                    *buf,
        unsigned                 len);

        LXxMETHOD(  const char *,
FromLocal) (
        LXtObjectID              self,
        char                    *neutral,
        const char              *local);

        LXxMETHOD(  const char *,
ToLocal) (
        LXtObjectID              self,
        char                    *local,
        const char              *neutral);

        LXxMETHOD(  const char *,
ToLocalAlias) (
        LXtObjectID              self,
        char                    *local,
        const char              *neutral);

        LXxMETHOD( LxResult,
AllocReference) (
        LXtObjectID              self,
        const char              *path,
        void                   **ppvObj);
} ILxFile1Service;

/*
 * - Initialize
 * passed a path to a real file, sets the device to that file if it's of
 * the right type for this device. Selects the root of the device for attributes
 * and scanning. Returns NOTFOUND otherwise.
 * - Select
 * passed a partial path, sets the object to refer to a sub-file within the
 * device. The sub-path is of the form "aa/bbb/c".
 * - Extract
 * writes the contents of the current file in the virtual device to the given
 * real file system location.
 * 
 * - Scan
 * performs a scan of the current location, calling the visitor for each
 * file inside the directory.
 * 
 * - Name
 * in scan mode this returns the raw name of the sub-file. Otherwise it returns
 * the nice, human-reablabe name of the current location.
 * 
 * - Date
 * returns the date string for the scan file or current location.
 * 
 * - Size
 * returns the size of the scan file or current location.
 * 
 */
typedef struct vt_ILxVirtualDevice {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        const char		*path);

        LXxMETHOD( LxResult,
Select) (
        LXtObjectID		 self,
        const char		*sub);

        LXxMETHOD( LxResult,
Extract) (
        LXtObjectID		 self,
        const char		*dest);

        LXxMETHOD( LxResult,
Scan) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);

        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        unsigned		*type);

        LXxMETHOD( LxResult,
Name) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
Date) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
Size) (
        LXtObjectID		 self,
        double			*bytes);
} ILxVirtualDevice;

/*
 * This returns LXe_TRUE if a path is absolute, and LXe_FALSE if it is not.
 * 
 * This compares two paths and returns true if they are equal. This respects case-sensitivity
 * and other quirks specific to the operating system. It doesn't follow symbolic links
 * or other directory traversal.
 * 
 * This parses a filename path, extracting the last portion of the path into the basename
 * buffer and the path into the path buffer.
 * 
 * This adds the base filename onto a path with the path separator defined by the OS.
 * If the basename is absolute it returns LXe_INVALIDARG.
 * 
 * This takes a filename and extension, and returns the same filename but with the
 * new extension. The extension string is just the part after the period.
 * 
 * This makes a filename relative to a path, if possible. This fails if the filename could
 * not be made relative.
 * 
 * This computes a unique filename given a base pattern by adding digits. For example,
 * if the path is "c:\a\b\myfile.ext", this will first see if
 * "c:\a\b\myfile.ext" exists.  If it does not, it will be returned.  If it does
 * exist, then the path will be changed to "c:\a\b\myfile_1.ext" and tested again,
 * and so on until the path is unique.
 * This method fails if the path portion doesn't exist.
 * 
 * 
 * Given a path to a directory, this creates the directories, if possible.
 * 
 * NONE indicates that the file does not exist or cannot be accessed for some reason.
 * UNKNOWN indicates that the file exists but is some unusual type.
 * 
 * This returns a combination of flags indicating if a file can be read and/or written.
 * This method always succeeds, even if the file doesn't exist.
 * 
 * This renames a file on disk, if possible.  This will also work on directories.
 * This can also be used to move files.
 * 
 * This copies a file from one path to another.  If a file already exists at the
 * destination path and overwrite is true, it will be overwritten with no warning
 * given. If overwrite is false, then the method will fail if a file already exists
 * at the destination.
 * 
 * 
 * This deletes a file from disk, if possible.  In general, this must be a file
 * (not a directory).
 * 
 * This deletes a dir from disk.
 * 
 * This opens a file in the application associated with it by the operating system.
 * 
 * 
 * This finds the file/folder and selects it in Explorer/Finder.  Calling this with
 * a folder will open the parent in Explorer/Finder and select it, while using
 * OpenFileWithDefaultApp() on a folder would show the contents of the folder itself.
 * 
 * This executes an arbitrary program given an argv-style array of arguments.  If
 * "show" is true, the application will be visible when launched; if false, it will
 * be hidden.  If force32 is true, the 32 bit version of the application will be
 * launched on a 64 bit system if available supports fat/universal binaries (such
 * as OS X); otherwise, the native version of the application will launch.
 * 
 * 
 * These two utilities convert between local paths and URLs.  These paths begin
 * with the "file://" URL prefix.
 * 
 * Local file and path names can be converted to and from neutral format with
 * these interfaces.  The value returned is the result of the conversion.
 * These conversions are raw, performing a simple conversion without validity
 * checks.  Aliases are not used in the first two methods, they are in 'ToLocalAlias'.
 * 
 * 
 * 
 * Takes a product name and version number and returns LXe_OK if there is a valid license.
 * 
 * It is often useful to know the modification time of a file in a platform-agnostic
 * format.  This method returns that as a string of "YYYY:MM:DD HH:MM:SS".  This
 * assures that sorting date strings using strcmp()-like functions puts the dates in
 * chronological order.
 * 
 * Allocate a redirection object from the service. When created it has no history
 * so no redirections are done.
 * 
 * This in-place modifies a C string, replacing characters with special meaning
 * in the OS (like slashes and colons) with underscores.  If replacedDot is true,
 * periods will also be replaced.  This should only be called on filenmaes, as it
 * will remove the slashes and colons from full paths.
 * This returns LXe_TRUE if the path was already legal, and LXe_FALSE if any
 * characters were replaced with underscores.
 * 
 * 
 * These functions are an API for Package (and zip) files.
 * - PkgCountFiles: Count the number of files in a package.
 * - PkgFilename: Give the filename in the package. Could be a something like directory/filename.xyz
 * - PkgHasFile: Search if a pkg owns a file.
 * - PkgExtract: Extract one specific files.
 * - PkgExtractAll: Extract all files. You can specific subDir is you want to extract only a specific directory in the package.
 * 
 */
typedef struct vt_ILxFileService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
FileSystemPath) (
        LXtObjectID		  self,
        const char		 *name,
        const char		**path);
        LXxMETHOD(  LxResult,
IsAbsolutePath) (
        LXtObjectID		 self,
        const char		*path);
        LXxMETHOD(  LxResult,
ArePathsEqual) (
        LXtObjectID		 self,
        const char		*path1,
        const char		*path2);
        LXxMETHOD(  LxResult,
ParsePath) (
        LXtObjectID		 self,
        const char		*filename,
        unsigned		 component,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
ComposePath) (
        LXtObjectID		 self,
        const char		*basename,
        const char		*path,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
SetExtension) (
        LXtObjectID		 self,
        const char		*filename,
        const char		*extension,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
MakeRelative) (
        LXtObjectID		 self,
        const char		*filename,
        const char		*path,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
MakeUnique) (
        LXtObjectID		 self,
        const char		*filename,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
MakeDirectory) (
        LXtObjectID		  self,
        const char		 *path);
        LXxMETHOD(  LxResult,
TestFileType) (
        LXtObjectID		 self,
        const char		*filename,
        unsigned		*type);
        LXxMETHOD(  LxResult,
TestFileMode) (
        LXtObjectID		 self,
        const char		*filename,
        unsigned		*mode);
        LXxMETHOD(  LxResult,
RenameFile) (
        LXtObjectID		 self,
        const char		*from,
        const char		*to);
        LXxMETHOD(  LxResult,
FileCopy) (
        LXtObjectID		 self,
        const char		*srcFilePath,
        const char		*dstFilePath,
        unsigned		 overwrite);
        LXxMETHOD(  LxResult,
FileDelete) (
        LXtObjectID		 self,
        const char		*filename);
        LXxMETHOD(  LxResult,
DirDelete) (
        LXtObjectID		 self,
        const char		*filename);
        LXxMETHOD(  LxResult,
OpenFileWithDefaultApp) (
        LXtObjectID		 self,
        const char		*filename);
        LXxMETHOD(  LxResult,
RevealInFileViewer) (
        LXtObjectID		 self,
        const char		*filename);
        LXxMETHOD(  LxResult,
Execute) (
        LXtObjectID		 self,
        const char	       **argv,
        int			 show,
        int			 force32);
        LXxMETHOD(  LxResult,
FileToURL) (
        LXtObjectID		 self,
        const char		*filename,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
FileFromURL) (
        LXtObjectID		 self,
        const char		*url,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
FromLocal) (
        LXtObjectID		 self,
        const char		*local,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
ToLocal) (
        LXtObjectID		 self,
        char			*neutral,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
ToLocalAlias) (
        LXtObjectID		 self,
        const char		*neutral,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
AllocReference) (
        LXtObjectID		 self,
        const char		*path,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
FindSequencePattern) (
        LXtObjectID		 self,
        const char		*filename,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
FindSequenceBounds) (
        LXtObjectID		 self,
        const char		*pattern,
        unsigned		*first,
        unsigned		*last);

        LXxMETHOD( LxResult,
GenerateSequenceName) (
        LXtObjectID		 self,
        const char		*pattern,
        unsigned		 frame,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
ValidateLicense) (
        LXtObjectID		 self,
        const char		*product,
        int			 versionNum);
        LXxMETHOD( LxResult,
FileDateString) (
        LXtObjectID		 self,
        const char		*filename,
        char			*buf,
        int			 len);
        LXxMETHOD( LxResult,
AllocRedirect) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
MakeLegalFilename) (
        LXtObjectID		  self,
        char			 *filename,
        int			  replaceDot);
        LXxMETHOD( unsigned,
PkgCountFiles) (
        LXtObjectID	 self,
        const char	*package);

        LXxMETHOD( LxResult,
PkgFilename) (
        LXtObjectID	 self,
        const char	*package,
        unsigned	 id,
        char		*buf,
        int		 len);

        LXxMETHOD( LxResult,
PkgHasFile) (
        LXtObjectID	 self,
        const char	*package,
        const char	*file);

        LXxMETHOD( LxResult,
PkgExtract) (
        LXtObjectID	 self,
        const char	*package,
        const char	*file,
        const char	*dest);

        LXxMETHOD( LxResult,
PkgExtractAll) (
        LXtObjectID	 self,
        const char	*package,
        const char	*dest,
        const char	*subDir);
} ILxFileService;

typedef struct vt_ILxFileReference {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Path) (
        LXtObjectID		 self,
        const char	       **path);

        LXxMETHOD( LxResult,
NiceName) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        unsigned		*type);

        LXxMETHOD( LxResult,
Mode) (
        LXtObjectID		 self,
        unsigned		*mode);

        LXxMETHOD( LxResult,
SubCount) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD( LxResult,
SubByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
} ILxFileReference;

/*
 * Configure the redirection to support neutral format names. This means that
 * references are in a format that is the same on all platforms, so that a file
 * saved on a PC can be loaded on a Mac. If this format is enabled aliases are 
 * also supported.
 * 
 * The search path for a redirection object is intended to be set once. Paths will
 * be searched in the order they're added.
 * 
 * This method takes a reference path and tries to find an absolute 
 * path to an existing asset matching the reference. The input reference may be
 * absolute or relative, and must be in neutral format if this object is also. The
 * file type is used to open a redirection dialog by the user, and can be left
 * null to suppress that.
 * 
 * A sequence filename (one that contains sequence pattern) can be found using
 * the same search criteria.
 * 
 * This method takes an absolute asset path and returns a reference. The 
 * reference may be relative if the asset can be found on the search path. For 
 * neutral format redirction the reference is platform-generic and may contain
 * user aliases.
 */
typedef struct vt_ILxFileRedirect {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
NeutralFormat) (
        LXtObjectID		 self,
        unsigned		 allow);
        LXxMETHOD( LxResult,
AddSearchPath) (
        LXtObjectID		 self,
        const char		*path);
        LXxMETHOD( LxResult,
Locate) (
        LXtObjectID		 self,
        const char		*path,
        const char		*type,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
LocateSequence) (
        LXtObjectID		 self,
        const char		*pattern,
        const char		*type,
        unsigned		*first,
        unsigned		*last,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
Reference) (
        LXtObjectID		 self,
        const char		*path,
        char			*buf,
        unsigned		 len);
} ILxFileRedirect;


        #define LXu_FILE1SERVICE	"D792F5C0-0555-4FC7-832C-D200CDA42D97"
        #define LXa_FILE1SERVICE	"fileservice"

/*
 * This function takes a neutral format filename as an asset reference and
 * locates its referand local file.  This is a well-defined mapping which
 * performs a search of the content path, and the filename returned is
 * guaranteed to exist.  LXe_NOTFOUND is returned if there is no such asset
 * file. The type is the file type string that would be passed to a file
 * dialog and indicates the type of file that this should be, or can be
 * null to indicate that no user alternates should be allowed. LXe_OK is
 * returned when the file was found as-is, and LXe_FILE_REMAP is returned
 * on a successful remap.
 * If the type argument is present, the user will be asked to locate missing
 * files, which can result in different return codes.  LXe_SKIP is returned
 * if the user chose to skip this file.  LXe_ABORT is returned if the user
 * chose to abort the entire load operation.  Note that LXe_SKIP is a fail
 * code.
 */

        #define LXe_SKIP		LXxFAILCODE(LXeSYS_AFILE,1)
        #define LXe_FILE_REMAP		LXxGOODCODE(LXeSYS_AFILE,2)


        #define LXu_VIRTUALDEVICE	"60B61E9D-17F3-4068-85C2-3799A73F5D95"
        #define LXa_VIRTUALDEVICE	"virtualdevice"
        // [export] ILxVirtualDevice vdev
        // [local]  ILxVirtualDevice

/*
 * Plug-ins can use the File service for various file operations, such as looking
 * up standard file paths by name, or copying files from one location to another.
 * Also see PlatformService for functions to walk the list of all aliased paths and
 * for walking the list of import paths.
 */

        #define LXu_FILESERVICE		"742B3D3D-1151-4AB7-AF4F-668D18468D7F"
        #define LXa_FILESERVICE		"fileservice2"
        // [python] ILxFileService:IsAbsolutePath	bool
        // [python] ILxFileService:ArePathsEqual	bool
        // [python] ILxFileService:TestFileType		bool
        // [python] ILxFileService:AllocReference	obj FileReference
        // [python] ILxFileService:AllocRedirect	obj FileRedirect

/*
 * FileSystemPath() returns the standard file path for a given name, as defined by
 * one of the LXsSYSTEM_PATH_ defines.
 */

        #define LXsSYSTEM_PATH_PROGRAM	 	"program"
        #define LXsSYSTEM_PATH_EXENAME	 	"exename"
        #define LXsSYSTEM_PATH_PROJECT	 	"project"
        #define LXsSYSTEM_PATH_TEMP	 	"temp"
        #define LXsSYSTEM_PATH_LICENSE	 	"license"
        #define LXsSYSTEM_PATH_RESOURCE		"resource"
        #define LXsSYSTEM_PATH_MODULE	 	"module"
        #define LXsSYSTEM_PATH_PREFS	 	"prefs"
        #define LXsSYSTEM_PATH_HELP	 	"help"
        #define LXsSYSTEM_PATH_USER	 	"user"
        #define LXsSYSTEM_PATH_CONTENT	 	"content"
        #define LXsSYSTEM_PATH_ASSET	 	"asset"
        #define LXsSYSTEM_PATH_PRESET	 	"preset"
        #define LXsSYSTEM_PATH_SAMPLE	 	"sample"
        #define LXsSYSTEM_PATH_CONFIGS		"configs"
        #define LXsSYSTEM_PATH_SCRIPTS		"scripts"
        #define LXsSYSTEM_PATH_DOCUMENTS	"documents"
        #define LXsSYSTEM_PATH_KITS		"kits"
        #define LXsSYSTEM_PATH_USER_KITS	"userkits"
        #define LXsSYSTEM_PATH_LOGS	 	"logs"
        #define LXsSYSTEM_PATH_CLOUDCACHE	"cloudcache"
        #define LXsSYSTEM_PATH_USER_CONTENT	"usercontent"

/*
 * The components of the path are the directory, the base filename with extension, the
 * root name without extension, and the extension itself.
 */

        #define LXiFILECOMP_DIRECTORY	 0
        #define LXiFILECOMP_BASENAME	 1
        #define LXiFILECOMP_ROOTNAME	 2
        #define LXiFILECOMP_EXTENSION	 3

/*
 * This returns LXe_TRUE if a file exists, and LXe_FALSE if it does not.  More detailed
 * information can be returned in the type argument (if non-NULL), and will be one of
 * the following defines.
 */

        #define LXiFILETYPE_NONE	 	0
        #define LXiFILETYPE_NORMAL	 	1
        #define LXiFILETYPE_DIRECTORY	 	2
        #define LXiFILETYPE_UNKNOWN	 	3
        #define LXiFILETYPE_UNRESOLVED	 	4



        #define LXiFILEMODE_READ	 	1
        #define LXiFILEMODE_WRITE	 	2


        #define LXu_FILEREFERENCE	"A18B9A9D-6623-4463-B6AF-469771B41485"
        // [local]  ILxFileReference
        // [python] ILxFileReference:SubByIndex		obj FileReference

/*
 * The staged file list contains a list of source and destination file paths,
 * that will be copied the next time modo is started up.
 * This copying is done before any plug-ins are loaded.
 */

        #define LXsSTAGED_FILE_LIST		"LxStagedFiles.txt"

/*
 * A file redirection object allows path names from a file to be mapped to an
 * equivalant path found through some method of redirection. This is normally
 * used when loading a file to find all other related assets.
 */

        #define LXu_FILEREDIRECT	"05DACE30-BFA0-453C-AB7A-33DF35827A35"
        // [local]  ILxFileRedirect

/*
 * None of these are currently used.
 */

//	#define LXeREMAP_DIRECT		LXxGOODCODE(LXeSYS_AFILE,3)
//	#define LXeREMAP_PATH		LXxGOODCODE(LXeSYS_AFILE,4)
//	#define LXeREMAP_PATTERN	LXxGOODCODE(LXeSYS_AFILE,5)
//	#define LXeREMAP_BASENAME	LXxGOODCODE(LXeSYS_AFILE,6)

#endif
