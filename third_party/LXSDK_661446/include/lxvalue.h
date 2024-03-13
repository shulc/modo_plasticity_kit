/*
 * LX value module
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
#ifndef LX_value_H
#define LX_value_H

typedef struct vt_ILxValueService ** ILxValueServiceID;
typedef struct vt_ILxValue ** ILxValueID;
typedef struct vt_ILxValue1 ** ILxValue1ID;
typedef struct vt_ILxStringConversion ** ILxStringConversionID;
typedef struct vt_ILxStringConversionNice ** ILxStringConversionNiceID;
typedef struct vt_ILxValueMath ** ILxValueMathID;
typedef struct vt_ILxValueReference ** ILxValueReferenceID;
typedef struct vt_ILxValueConversion ** ILxValueConversionID;
typedef struct vt_ILxAttributes ** ILxAttributesID;
typedef struct vt_ILxMessage ** ILxMessageID;
typedef struct vt_ILxValueArray ** ILxValueArrayID;
typedef struct vt_ILxValueArray1 ** ILxValueArray1ID;
typedef struct vt_ILxArray ** ILxArrayID;
typedef struct vt_ILxScriptQuery ** ILxScriptQueryID;
typedef struct vt_ILxStringTag ** ILxStringTagID;
typedef struct vt_ILxMatrix ** ILxMatrixID;
typedef struct vt_ILxQuaternion ** ILxQuaternionID;
typedef struct vt_ILxVisitor ** ILxVisitorID;
typedef struct vt_ILxTextEncoding ** ILxTextEncodingID;
typedef struct vt_ILxTextEncodingService ** ILxTextEncodingServiceID;

#include <lxcom.h>
#include <lxvmath.h>


/*
 * Internal numeric codes are sometimes stored in files: data files, config
 * files, and even macros.  Since these numeric codes are subject to change as
 * algorithms and systems get updated, we provide a system of hints to use
 * when storing these values to files so that we can cope with changes when
 * reading old ones.  Right now the system is simple, but it can be expanded
 * as required to cope with more sophisticated conversions.
 * The hints come in the form of a null-terminated array of hint structs,
 * each one linking a numeric value to a text token.  Tokens that start with "+"
 * indicate bit masks, and other values represent choices.  The tokens should
 * not start with numeric or punctuation characters, and should not contain
 * spaces.
 */
typedef struct st_LXtTextValueHint {
        int			 value;
        const char		*text;
} LXtTextValueHint;


/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * This encodes a numeric value as a string.  If the 'buf' pointer is null, then
 * a rolling buffer will be allocated and returned.  If the hint pointer is null
 * then the value is written as a plain signed integer.
 * This will return LXe_OK_INEXACT_MATCH when an integer is provided that does
 * not exactly map to one of the choices.  This is only returned if there are
 * choices.  LXe_OK_NO_CHOICES is returned if there are no choices at all.
 * In both cases, the raw integer is encoded into the string buffer.  Both
 * codes are "OK" codes, and do not signify an error, but rather provide hints
 * about the content of the encoded string, and may help instruct an code path
 * if you do need an exact match or were expecting choices.
 * 
 * 
 * This method decodes a string using the hint array.  If the string is a
 * number it will be returned directly after being clamped to min or max limits.
 * If nothing is recognized then the function end-of-list will be returned.
 * This will return LXe_NOTFOUND when the string does not exactly match any
 * text hints and cannot be converted into an integer (i.e., it doesn't start
 * with a number).  LXe_OK_NO_CHOICES is returned when the string was
 * sucessfully converted from a number into an integer and may have been
 * constrained to any min/max hints present, but the hints contain no actual
 * choices.  This may occur in the case of a hints array that is used only for
 * min/max or similar properties, and is not meant to have a list of choices.
 * 
 * 
 * This method creates a new value object of the given type.
 * 
 * This gets the intrinsic type for a given value type, as one of the LXi_TYPE_* choices.
 * 
 * There are cases where it is useful to copy a text hints array.  These
 * methods can be used to do just that, and to free it when it is no longer
 * needed.  These functions will safely handle NULL arrays, and will simply
 * fail.
 * 
 * 
 * Check a float for NaN or infinity. A zero return value is OK.
 * 
 * Returns the global Frames Per Second.
 * 
 * Given a time and using the global Frames Per Second, returns an equivalent frame.
 * 
 * Given a frame and using the global Frames Per Second, returns an equivalent time.
 * 
 * Given a time and a Frames Per Second, returns an equivalent frame.
 * 
 * Given a frame and a Frames Per Second, returns an equivalent time.
 * 
 * Given two different value type names, returns an ILxValueConversion object that
 * can be used to convert from one type to the other.
 */
typedef struct vt_ILxValueService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
TextHintEncode) (
        LXtObjectID		 self,
        int			 value,
        const LXtTextValueHint	*hint,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
TextHintDecode) (
        LXtObjectID		 self,
        const char		*buf,
        const LXtTextValueHint	*hint,
        int			*value);
        LXxMETHOD(  LxResult,
CreateValue) (
        LXtObjectID		 self,
        const char		*type,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ValueType) (
        LXtObjectID		 self,
        const char		*type,
        unsigned		*valType);
        LXxMETHOD(  LxResult,
TextHintDuplicate) (
        LXtObjectID		  self,
        const LXtTextValueHint	 *hint,
        LXtTextValueHint	**copy);
        LXxMETHOD(  LxResult,
TextHintFreeDuplicate) (
        LXtObjectID		  self,
        LXtTextValueHint	 *copy);
        LXxMETHOD(  int,
FloatType) (
        LXtObjectID		 self,
        float			 val);
        LXxMETHOD(  double,
GetFPS) (
        LXtObjectID		 self);
        LXxMETHOD(  double,
TimeToFrame) (
        LXtObjectID		 self,
        double			 time);
        LXxMETHOD(  double,
FrameToTime) (
        LXtObjectID		 self,
        double			 frame);
        LXxMETHOD(  double,
TimeToFrameFPS) (
        LXtObjectID		 self,
        double			 time,
        double			 fps);
        LXxMETHOD(  double,
FrameToTimeFPS) (
        LXtObjectID		 self,
        double			 frame,
        double			 fps);
        LXxMETHOD(  LxResult,
ConvertValues) (
        LXtObjectID		 self,
        const char		*from,
        const char		*to,
        void		       **ppvObj);
} ILxValueService;

/*
 * The Clone method returns a duplicate of the value server. The data for the
 * value is also copied, allowing the clone to be modified, without affecting
 * the source value.
 * 
 * Similar to Clone, the Copy method will be copy the data from the Value object,
 * however, instead of returning a new object, the data will be copied to the
 * object passed in. The target and source Value servers must have the same
 * implementation.
 * 
 * The Compare method will compare this Value object against another of the same
 * type. This works in a similar way to string comparison, with a diff value of
 * -1 for less than, 0 for equal to, and 1 for greater than. If the objects are
 * the same, the result code will be LXe_TRUE.
 * 
 * The Type method returns the intrinsic type, in a similar way to the Attributes
 * interface. The return value will either be LXi_TYPE_INTEGER, LXi_TYPE_FLOAT,
 * LXi_TYPE_STRING or LXi_TYPE_OBJECT.
 * 
 * The TypeName method indirectly returns a string representing the name of the
 * value type. This is usually the name of the server that implements the value,
 * but this is not guaranteed.
 * 
 * In some cases, Value objects are simply containers for other value types. The
 * SubTypeName method returns the name of the value type contained.
 * 
 * The actual value of the value can be read and optionally set several
 * different ways.
 * 
 * A somewhat more raw method can give generic access to the intrinsic types.
 * For integer types this is a pointer to int; for float types it's a pointer
 * to double; for string types it's a pointer to char. Other value types may
 * return null.
 */
typedef struct vt_ILxValue {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Clone) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
Copy) (
        LXtObjectID		 self,
        LXtObjectID		 from);
        LXxMETHOD( LxResult,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        int			*diff);
        LXxMETHOD( unsigned int,
Type) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
SubTypeName) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		 self,
        int			*val);

        LXxMETHOD(  LxResult,
SetInt) (
        LXtObjectID		 self,
        int			 val);

        LXxMETHOD(  LxResult,
GetFlt) (
        LXtObjectID		 self,
        double			*val);

        LXxMETHOD(  LxResult,
SetFlt) (
        LXtObjectID		 self,
        double			 val);

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
SetString) (
        LXtObjectID		 self,
        const char		*val);
        LXxMETHOD(  void *,
Intrinsic) (
        LXtObjectID		 self);
} ILxValue;

typedef struct vt_ILxValue1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Clone) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Copy) (
        LXtObjectID		 self,
        LXtObjectID		 from);

        LXxMETHOD( LxResult,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        int			*diff);

        LXxMETHOD( unsigned int,
Type) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		 self,
        int			*val);

        LXxMETHOD(  LxResult,
SetInt) (
        LXtObjectID		 self,
        int			 val);

        LXxMETHOD(  LxResult,
GetFlt) (
        LXtObjectID		 self,
        double			*val);

        LXxMETHOD(  LxResult,
SetFlt) (
        LXtObjectID		 self,
        double			 val);

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
SetString) (
        LXtObjectID		 self,
        const char		*val);

        LXxMETHOD(  void *,
Intrinsic) (
        LXtObjectID		 self);
} ILxValue1;

/*
 * This interface allows simple string equivalence for COM objects.  The
 * Encode() function writes the value of the object to a string with the given
 * number of available bytes (including null termination), and the Decode()
 * parses a string setting the value of the object to match.
 */
typedef struct vt_ILxStringConversion {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Encode) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
Decode) (
        LXtObjectID		 self,
        const char		*buf);
} ILxStringConversion;

/*
 * Nice is the same as raw. Too bad there's no reasonable way to use the same
 * interface with different GUIDs.
 */
typedef struct vt_ILxStringConversionNice {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Encode) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
Decode) (
        LXtObjectID		 self,
        const char		*buf);
} ILxStringConversionNice;

/*
 * Numeric or quasi-numeric values can be modified through the value-math
 * interface.
 */
typedef struct vt_ILxValueMath {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Step) (
        LXtObjectID		 self,
        int			 direction);

        LXxMETHOD( int,
Detent) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Add) (
        LXtObjectID		 self,
        double			 delta);

        LXxMETHOD( LxResult,
Multiply) (
        LXtObjectID		 self,
        double			 factor);

        LXxMETHOD( LxResult,
Blend) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        double			 blend);
} ILxValueMath;

/*
 * Some values are references to other object types. This interface allows access
 * to the referenced object, as well as a query for knowing if a reference is set.
 */
typedef struct vt_ILxValueReference {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
IsSet) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
GetObject) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
SetObject) (
        LXtObjectID		 self,
        LXtObjectID		 obj);
} ILxValueReference;

/*
 * Value Conversion servers allow one value type to be converted into another. For
 * example, converting an integer into a string.
 * This method should return LXe_TRUE or LXe_FALSE if the value type can handle a
 * conversion from one type to another.
 * 
 * 
 * When the conversion occurs, the "from" value and it's type is passed to this
 * method along with the "to" value, and it's type. This method should set the
 * value of the "to" object, using the value of the "from" object.
 */
typedef struct vt_ILxValueConversion {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        const char		*fromType,
        const char		*toType);
        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        const char		*fromType,
        LXtObjectID		 to,
        const char		*toType);
} ILxValueConversion;

/*
 * Return the number of attributes.
 * Return the name of the attribute at given index, or LXe_OUTOFBOUNDS for bad
 * index choices.
 * 
 * Return the index given the name, or LXe_NOTFOUND.
 * 
 * Return the basic attribute type which indicates what intrinsic data type is
 * used to store it.  That is given by one of the types below.
 * 
 * Return the attribute type name.  This is the name of any of the available
 * value types.
 * 
 * Return a read-only array of text value hints for the given attribute.  This
 * may return null if there are none or if there is any other failure. Note that
 * this array may be volatile and should not be stored.
 * 
 * Once the list of attributes and their types has been determined, the following
 * methods can be used to read and write their values given their index (from
 * 0 to Count-1).
 * - Value
 * This gets the ILxValue associated with the attribute.  The interface has been
 * acquired for the calling client and needs to be released when done.  If 'writeOK'
 * is true the object will be writable, and changes to the value should be done
 * using the appropriate object interface.
 * 
 * - GetInt, SetInt
 * These get and set the value of integer attributes.
 * 
 * - GetFlt, SetFlt
 * These get and set the value of floating-point attributes.
 * 
 * - GetString, SetString
 * These get and set the value of string attributes.  Note that GetString() returns
 * a "raw" string when used with non-string datatypes.  "Nice" strings can be obtained
 * by passing the result of Value() through an appropriate StringConversion.
 * 
 */
typedef struct vt_ILxAttributes {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char 	       **name);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char 		*name,
        unsigned int		*index);
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int 		*type);
        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char 	       **tname);
        LXxMETHOD(  const LXtTextValueHint *,
Hints) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD(  LxResult,
Value) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj,
        int			 writeOK);

        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			*val);

        LXxMETHOD(  LxResult,
SetInt) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			 val);

        LXxMETHOD(  LxResult,
GetFlt) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			*val);

        LXxMETHOD(  LxResult,
SetFlt) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			 val);

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		 self,
        unsigned int		 index,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
SetString) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char		*val);
} ILxAttributes;

/*
 * This returns the code, which can be an error, info (success) or warning LxResult.
 * 
 * This sets that code.
 * 
 * To set the message, the client provides a message table name and either a
 * message name or numeric ID representing the message.  If the text name is
 * NULL, the ID is converted to text and used instead. Setting a message clears
 * any existing message.
 * 
 * Messages in message tables may have arguments marked in the form of %1, %2, etc.
 * One of the SetArgument...() functions should be called for each to provide a
 * meaningful dynamic value to the user.
 * Note that these argument indices match the numbers in the message string itself;
 * if you want to set %1, use argument index 1.  Technically, you can have a %0 and
 * use arg index 0, but that is discouraged.
 * 
 * 
 * 
 * 
 * 
 * This resets a message object to LXe_OK and clears the string to NULL.
 * 
 * Some clients need access to the table and message name.
 * 
 * 
 * To set the message from a result code, the client provides the numeric ID
 * representing the message.  Setting a message clears any existing message.
 * This also sets the result code itself by treating the numeric ID as an
 * LxResult.
 */
typedef struct vt_ILxMessage {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Code) (
        LXtObjectID		  self );
        LXxMETHOD(  LxResult,
SetCode) (
        LXtObjectID		  self,
        LxResult		  code );
        LXxMETHOD(  LxResult,
SetMessage) (
        LXtObjectID		  self,
        const char		 *table,
        const char		 *name,
        unsigned		  id);
        LXxMETHOD(  LxResult,
SetArgumentInt) (
        LXtObjectID		  self,
        unsigned		  arg,
        int			  value);
        LXxMETHOD(  LxResult,
SetArgumentFloat) (
        LXtObjectID		  self,
        unsigned		  arg,
        double			  value);
        LXxMETHOD(  LxResult,
SetArgumentString) (
        LXtObjectID		  self,
        unsigned		  arg,
        const char		 *string);
        LXxMETHOD(  LxResult,
SetArgumentObject) (
        LXtObjectID		  self,
        unsigned		  arg,
        LXtObjectID		  object);
        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
Table) (
        LXtObjectID		  self,
        const char		**table);
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
SetMessageResult) (
        LXtObjectID		  self,
        unsigned		  id);
} ILxMessage;

/*
 * These returns the type of the values stored in the container.  Type is an
 * LXi_TYPE_* identifier, while TypeName is the ExoType's actual name string.
 * 
 * This returns the number of values currently in the container.
 * 
 * This adds an uninitialized value to the container, optionally returning it to
 * the caller.  This is useful if you just need a dummy value to fill a gap.
 * Another common use is to the returned value object to decode a string.
 * 
 * These add new values to the container.  Note that the original value is still
 * owned by the client.
 * Also note that these only work on matching datatypes -- notably, AddString() will
 * only work if the value array is itself representing a string.  If you want have a
 * string decoded as a value to add to the array, use AddEmptyValue() to add an empty
 * value object to the array, then call that object's SetString() method to decode
 * the string into it.
 * 
 * 
 * These get values out of the container.  Note that the ILxValueID provided
 * from GetValue() must be released by the caller.
 * Also note that GetString() can be used on non-string datatypes, and will return
 * a "raw" string.  "Nice" strings can be obtained by passing the result of Value()
 * through an appropriate StringConversion.
 * 
 * 
 * This returns the index of the first unique value found that is different
 * from the 0th index, or -1 if all the values are identical.  This is useful
 * for creating mixed argument lists for user interfaces.
 * 
 * This empties the container, freeing all values within.
 * 
 * This removes an element from the array at the specified index. If the index is
 * out of bounds, the function returns LXe_OUTOFBOUNDS.
 * 
 * These methods set the value of an existing element in the value array, replacing
 * the value stored at the specified index.
 */
typedef struct vt_ILxValueArray {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		  self,
        unsigned int		 *type );

        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		  self,
        const char		**name );
        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		  self );
        LXxMETHOD(  LxResult,
AddEmptyValue) (
        LXtObjectID		 self,
        void		       **ppvObj );
        LXxMETHOD(  LxResult,
AddValue) (
        LXtObjectID		  self,
        LXtObjectID		  value );

        LXxMETHOD(  LxResult,
AddInt) (
        LXtObjectID		  self,
        int			  value );

        LXxMETHOD(  LxResult,
AddFloat) (
        LXtObjectID		  self,
        double			  value );

        LXxMETHOD(  LxResult,
AddString) (
        LXtObjectID		  self,
        const char		 *value );
        LXxMETHOD(  LxResult,
GetValue) (
        LXtObjectID		  self,
        unsigned int		  index,
        void		       **ppvObj );

        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		  self,
        unsigned int		  index,
        int			 *value );

        LXxMETHOD(  LxResult,
GetFloat) (
        LXtObjectID		  self,
        unsigned int		  index,
        double			 *value );

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		  self,
        unsigned int		  index,
        char			 *buf,
        unsigned		  len );
        LXxMETHOD(  LxResult,
FirstUnique) (
        LXtObjectID		  self,
        unsigned int		 *uniqueIndex );
        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		  self );
        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		  self,
        unsigned int		  index );
        LXxMETHOD(  LxResult,
SetValue) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  value );

        LXxMETHOD(  LxResult,
SetInt) (
        LXtObjectID		  self,
        unsigned int		  index,
        int			  value );

        LXxMETHOD(  LxResult,
SetFloat) (
        LXtObjectID		  self,
        unsigned int		  index,
        double			  value );

        LXxMETHOD(  LxResult,
SetString) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char		 *value );
} ILxValueArray;

typedef struct vt_ILxValueArray1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		  self,
        unsigned int		 *type );

        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		  self,
        const char		**name );

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
AddEmptyValue) (
        LXtObjectID		 self,
        void		       **ppvObj );

        LXxMETHOD(  LxResult,
AddValue) (
        LXtObjectID		  self,
        LXtObjectID		  value );

        LXxMETHOD(  LxResult,
AddInt) (
        LXtObjectID		  self,
        int			  value );

        LXxMETHOD(  LxResult,
AddFloat) (
        LXtObjectID		  self,
        double			  value );

        LXxMETHOD(  LxResult,
AddString) (
        LXtObjectID		  self,
        const char		 *value );

        LXxMETHOD(  LxResult,
GetValue) (
        LXtObjectID		  self,
        unsigned int		  index,
        void		       **ppvObj );

        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		  self,
        unsigned int		  index,
        int			 *value );

        LXxMETHOD(  LxResult,
GetFloat) (
        LXtObjectID		  self,
        unsigned int		  index,
        double			 *value );

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		  self,
        unsigned int		  index,
        char			 *buf,
        unsigned		  len );

        LXxMETHOD(  LxResult,
FirstUnique) (
        LXtObjectID		  self,
        unsigned int		 *uniqueIndex );

        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		  self );
} ILxValueArray1;

typedef struct vt_ILxArray {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj );
} ILxArray;

/*
 * - LXe_QUERY_UNKNOWN_SERVICE
 * Unknown service, usually used by those looking up a script service by name.
 * - LXe_QUERY_UNKNOWN_SERVICE
 * Service exists, but does not have an ILxScriptQuery inteface, usually because the
 * ScriptQuery() method of the service returned LXe_NOTIMPL.
 * - LXe_QUERY_UNKNOWN_ATTRIBUTE
 * The attribute being queried is not known by the service.
 * 
 * - LXe_QUERY_MISMATCHED_TYPE
 * The attribute expects a type that is different from the type in the ILxValueArray
 * object.
 * 
 * - LXe_QUERY_SELECT_FAILED
 * Attempt to select an item failed, possibly because it doesn't exist, is of the wrong
 * type of the attribute, or the attribute doesn't require a selection.
 * 
 * - LXe_QUERY_NEED_SELECTION
 * The attribute requires a selection to operation on.
 * 
 * - LXe_QUERY_MISMATCHED_SELECTION
 * Although something is selected, it doesn't match the attribute being queried.
 * 
 * - LXe_QUERY_NOT_APPLICABLE_TO_SELECTED
 * The attribute is not applicable to the current selection, such as when the selected
 * item does not have the property being queried.
 * 
 * - LXe_QUERY_ERROR
 * General error querying the selection.
 * 
 * 
 * This selects what a query will obtain values for.  The attribute is the class
 * that we're querying, which might be "command.username" for the name of a
 * command; only the first part is looked at for the class, so "command" is fine.
 * which is the thing we're getting the data from.  The which argument depends on
 * the kind of attribute; for commands, it might be the name of the command to
 * get information for.
 * 
 * 
 * Once selected, we can query the selected item for it's values by providing an
 * attribute and an ILxValueArray object.  For a list of all possible attributes,
 * use NULL or an empty string for the attribute string.  Note that both NULL and
 * the empty string "" must be supported, as it can be difficult to provide NULL
 * from a script.
 * 
 * The type (LXi_TYPE_*) of the attribute can be obtained with this method.
 * The ILxValueArrayID passed to Query() must be of this type.
 * 
 * The specific ExoType name can be read with this method.
 */
typedef struct vt_ILxScriptQuery {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        const char		*attribute,
        const char	        *which);
        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		 self,
        const char		*attribute,
        LXtObjectID		 query);
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        const char		*attribute,
        int			*type);
        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		  self,
        const char		 *attribute,
        const char		**type);
} ILxScriptQuery;

/*
 * The ID is an LXtID4, which can be generated with the LXxID4() macro.  This
 * method gets the tag string for an ID, or returns NOTFOUND if none.
 * This sets the value of a tag, overwriting the one for the given ID.  Passing
 * null for the string pointer will clear the tag.
 * 
 * This methods gets the total number of tags.
 * 
 * This method returns the type and value of a tag by index.
 */
typedef struct vt_ILxStringTag {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Get) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char	       **tag);
        LXxMETHOD( LxResult,
Set) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*tag);
        LXxMETHOD( LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD( LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtID4			*type,
        const char	       **tag);
} ILxStringTag;

/*
 * Matrices are one of the more common complex types, so we provide an interface
 * (polymorphic with ILxValue-type objects) to access them more directly.
 * These functions allow 3x3 and 4x4 transformation matrices to be read.
 * 
 * As a convenience, this method composes a vector with the matrix.
 * 
 * Writable matrices have some operations to change them. First directly:
 * 
 * Then indirectly:
 */
typedef struct vt_ILxMatrix {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Get3) (
        LXtObjectID		 self,
        LXtMatrix		 mat3);

        LXxMETHOD( LxResult,
Get4) (
        LXtObjectID		 self,
        LXtMatrix4		 mat4);

        LXxMETHOD( LxResult,
GetOffset) (
        LXtObjectID		 self,
        LXtVector		 offset);
        LXxMETHOD( LxResult,
MultiplyVector) (
        LXtObjectID		 self,
        const LXtVector		 vector,
        LXtVector		 result);
        LXxMETHOD( LxResult,
Set3) (
        LXtObjectID		 self,
        const LXtMatrix		 mat3);

        LXxMETHOD( LxResult,
Set4) (
        LXtObjectID		 self,
        const LXtMatrix4	 mat4);

        LXxMETHOD( LxResult,
SetOffset) (
        LXtObjectID		 self,
        const LXtVector		 offset);
        LXxMETHOD( LxResult,
SetIdentity) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Multiply3) (
        LXtObjectID		 self,
        const LXtMatrix		 mat3);

        LXxMETHOD( LxResult,
Multiply4) (
        LXtObjectID		 self,
        const LXtMatrix4	 mat4);

        LXxMETHOD( LxResult,
Invert) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Transpose) (
        LXtObjectID		 self);
} ILxMatrix;

/*
 * Quaternions are often useful when working with rotations, however they are a
 * rather complex data type, so we provide an interface (polymorphic ILxValue-type
 * object) to access them more directly.
 * These functions allow the quaternion to be read. Either as a direct quaternion,
 * a 3x3 matrix, or as an angle + axis.
 * 
 * Writable quaternions have some operations to change them.
 */
typedef struct vt_ILxQuaternion {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
GetQuaternion) (
        LXtObjectID		 self,
        LXtQuaternion		 q);

        LXxMETHOD( LxResult,
GetMatrix) (
        LXtObjectID		 self,
        LXtMatrix		 mat3);

        LXxMETHOD( LxResult,
GetAngleAxis) (
        LXtObjectID		 self,
        double			*ang,
        LXtVector		 axis);
        LXxMETHOD( LxResult,
SetQuaternion) (
        LXtObjectID		 self,
        const LXtQuaternion	 q);

        LXxMETHOD( LxResult,
SetMatrix) (
        LXtObjectID		 self,
        const LXtMatrix		 mat3);

        LXxMETHOD( LxResult,
SetAngleAxis) (
        LXtObjectID		 self,
        double			 ang,
        const LXtVector		 axis);
} ILxQuaternion;

/*
 * A visitor is a general-purpose object created by SDK clients when they want
 * to perform some action from inside the app. The single Evaluate() method
 * can be called for each element in a database, for example, or just when the
 * client wants to do something in a specific context. If this method returns a
 * value other than LXe_OK, the enumeration will stop and the enumerate method
 * will return the result code.
 */
typedef struct vt_ILxVisitor {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self);
} ILxVisitor;

/*
 * - Default
 * Return the system default text encoding. It returns UTF-8 for OSX and Linux and others for
 * Windows.
 * - Source
 * Return the current text encoding for source text.
 * - Target
 * Return the current text encoding for source text.
 * - SetSource
 * Set a text encoding for source text. The initial source encoding is set by
 * "Default" method.
 * 
 * - SetTarget
 * Set a text encoding for target text to convert to.
 * 
 * - Convert
 * Convert a string encoded by source to a given buffer with target encoding.
 * 
 * - NumChar
 * Returns the length of a string in logical characters. If 'target' is true,
 * the string is handled by target encoding, otherwise source encoding is used.
 * 
 * - PullChar
 * Gets the first character's numeric value in the current code page, and
 * returns a pointer to the next character, or null if the the string was empty.
 * If 'target' is true, the string is handled by target encoding, otherwise
 * source encoding is used.
 * 
 * 
 */
typedef struct vt_ILxTextEncoding {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Default) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
Source) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
Target) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetSource) (
        LXtObjectID		 self,
        unsigned		 encoding);

        LXxMETHOD(  LxResult,
SetTarget) (
        LXtObjectID		 self,
        unsigned		 encoding);

        LXxMETHOD(  LxResult,
Convert) (
        LXtObjectID		 self,
        const char		*src,
        char			*buf,
        unsigned		 max);
        LXxMETHOD(  int,
NumChar) (
        LXtObjectID		 self,
        const char 		*string,
        int			 target);

        LXxMETHOD(  const char *,
PullChar) (
        LXtObjectID		 self,
        const char 		*string,
        int			*code,
        int			*len,
        int			 target);
} ILxTextEncoding;

typedef struct vt_ILxTextEncodingService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Allocate) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxTextEncodingService;

/*
 * This COM interface provides some useful functions for dealing with values.
 */

        #define LXu_VALUESERVICE		"DD2C3059-2CD0-4c7d-860C-CF353CFB2F92"
        #define LXa_VALUESERVICE		"valueservice"

        #define LXe_OK_INEXACT_MATCH		LXxGOODCODE (LXeSYS_VALUE, 1)
        #define LXe_OK_NO_CHOICES		LXxGOODCODE (LXeSYS_VALUE, 2)

        #define LXe_VALUE_UNKNOWN_EXOTYPE	LXxFAILCODE (LXeSYS_VALUE, 1)

        // [python] ILxValueService:CreateValue	obj Value
        // [python] ILxValueService:ConvertValues obj ValueConversion


        #define LXiFLOATTYPE_NUMBER	 0
        #define LXiFLOATTYPE_NAN	-1
        #define LXiFLOATTYPE_INFINITY	 1

/*
 * For various reasons ranging from I/O to UI, it's very convenient to be able
 * to treat data values in a uniform manner. Value servers provide a mechanism
 * for presenting any type of value/structure to Nexus, along with standard methods
 * for manipulating the data. These value types can then be used as channels on
 * items, as attributes on commands and tools, or simply for passing data between
 * systems.
 */

        #define LXu_VALUE	"83065459-D9EA-11E8-AEB4-E200E9309701"
        #define LXa_VALUE	"value2"
        // [export]  ILxValue
        // [local]   ILxValue
        // [const]   ILxValue:Compare
        // [const]   ILxValue:Type
        // [const]   ILxValue:GetInt
        // [const]   ILxValue:GetFlt
        // [const]   ILxValue:GetString
        // [const]   ILxValue:Intrinsic
        // [default] ILxValue:Intrinsic = 0
        // [python]  ILxValue:Clone	obj Value


        #define LXu_VALUE1		"62E1DBE9-2FFE-4B5C-B286-E54E79415303"
        #define LXa_VALUE1		"value"

/*
 * There are actually two variants of this interfaces that an object can
 * provide.  The "raw" version writes values in a native format, most suitable
 * for scripting of file I/O.  The "nice" version writes the value in a format
 * suitable for human reading, and parses a more extensive range of possible
 * human input.
 */

        #define LXu_STRINGCONVERSION		"5CB3EEDB-E4E0-499E-B0BA-A7FB51BABE3C"
        // [export] ILxStringConversion str
        // [local]  ILxStringConversion
        // [const]  ILxStringConversion:Encode

        #define LXu_STRINGCONVERSIONNICE	"5407328B-DE99-4F15-866F-F6E214FFA412"
        // [export] ILxStringConversionNice niceStr
        // [local]  ILxStringConversionNice
        // [const]  ILxStringConversionNice:Encode


        #define LXiDETENT_NONE	 0
        #define LXiDETENT_MINOR	 1
        #define LXiDETENT_MAJOR	 2


        #define LXu_VALUEMATH	"752B4D2E-6F13-4B2C-B0B3-0BA8CA6B0692"
        // [export] ILxValueMath math
        // [local]  ILxValueMath
        // [const]  ILxValueMath:Detent


        #define LXu_VALUEREFERENCE	"0567BC88-F782-426E-98C5-8302FD52D9E4"
        // [local]  ILxValueReference
        // [const]  ILxValueReference:IsSet
        // [const]  ILxValueReference:GetObject

        // [python] ILxValueReference:IsSet	bool
        // [python] ILxValueReference:GetObject	obj Unknown


        #define LXu_VALUECONVERSION	"AE427D16-AA5E-4135-8722-38D69F48F9EC"
        #define LXa_VALUECONVERSION	"valueconversion"
        // [local]  ILxValueConversion
        // [export] ILxValueConversion conv

/*
 * The attributes interface typically does not stand on its own.  Instead it's
 * one of an object's polymorphic features, which packages the internal state
 * of the object into a common format.
 */

        #define LXu_ATTRIBUTES	"117957D0-5A13-11D7-A18C-000A95765C9E"
        // [export] ILxAttributes attr
        // [local]  ILxAttributes
        // [const]  ILxAttributes:Count
        // [const]  ILxAttributes:Name
        // [const]  ILxAttributes:Lookup
        // [const]  ILxAttributes:Type
        // [const]  ILxAttributes:TypeName
        // [const]  ILxAttributes:Hints
        // [const]  ILxAttributes:GetInt
        // [const]  ILxAttributes:GetFlt
        // [const]  ILxAttributes:GetString

        // [python] ILxAttributes:Value		obj Unknown

/*
 * The intrinsic type returned by Type() is one of the following codes:
 * - LXi_TYPE_INTEGER, LXi_TYPE_FLOAT
 * The attribute is number, either an integer (int) of a floating point number
 * (double).  Booleans and axes are considered integers for this purpose.
 * - LXi_TYPE_STRING
 * The attribute is a string, and can be read or set as a null-terminated array
 * of bytes.
 * 
 * - LXi_TYPE_OBJECT
 * The attribute is a complex object, and is accessed as an ILxValue interface.
 * 
 */

        #define LXi_TYPE_OBJECT		0
        #define LXi_TYPE_INTEGER	1
        #define LXi_TYPE_FLOAT		2
        #define LXi_TYPE_STRING		3

/*
 * The type name can be one of the nexus intrinsic types here, or it can be a
 * value type implemented by a plug-in server of the "value" class.
 */

        #define LXsTYPE_INTEGER		"integer"
        #define LXsTYPE_FLOAT		"float"
        #define LXsTYPE_DISTANCE	"distance"
        #define LXsTYPE_PERCENT		"percent"
        #define LXsTYPE_ANGLE		"angle"
        #define LXsTYPE_FLOAT3		"float3"
        #define LXsTYPE_DISTANCE3	"distance3"
        #define LXsTYPE_PERCENT3	"percent3"
        #define LXsTYPE_ANGLE3		"angle3"
        #define LXsTYPE_TIME		"time"
        #define LXsTYPE_LIGHT		"light"
        #define LXsTYPE_STRING		"string"
        #define LXsTYPE_FILEPATH	"filepath"
        #define LXsTYPE_UVCOORD		"uvcoord"
        #define LXsTYPE_BOOLEAN		"boolean"
        #define LXsTYPE_AXIS		"axis"
        #define LXsTYPE_MEMORY		"memory"
        #define LXsTYPE_PIXEL		"pixel"
        #define LXsTYPE_FPIXEL		"fpixel"
        #define LXsTYPE_COLOR		"color"
        #define LXsTYPE_COLOR1		"color1"
        #define LXsTYPE_MATRIX3		"matrix3"
        #define LXsTYPE_MATRIX4		"matrix4"
        #define LXsTYPE_DATETIME	"datetime"
        #define LXsTYPE_TOD		"timeofday"
        #define LXsTYPE_DATE		"date"
        #define LXsTYPE_OBJREF		"objref"
        #define LXsTYPE_VERTMAPNAME	"vertmapname"
        #define LXsTYPE_FORCE		"force"
        #define LXsTYPE_ACCELERATION	"acceleration"
        #define LXsTYPE_SPEED		"speed"
        #define LXsTYPE_MASS		"mass"
        #define	LXsTYPE_QUATERNION	"quaternion"
        #define	LXsTYPE_FOCALLENGTH	"focallength"
        #define LXsTYPE_NONE		"none"

/*
 * Hints for the COM header compiler.
 */

        // [default] ILxAttributes:Count = 0
        // [default] ILxAttributes:Hints = 0

/*
 * Error messages can be managed through the use of the ILxMessage
 * interface.  These objects contain the result code, a message, and values for
 * each of the arguments in the message string.
 */

        #define LXu_MESSAGE		"DDDBF46A-0865-4AB7-9962-72E7B477FD22"
        #define LXa_MESSAGE		"message"
        // [export] ILxMessage msg
        // [local]  ILxMessage

/*
 * The ILxValueArray interface is a container for multiple values of the same type.
 * There can be zero or more values of any given type in the container, and the
 * object has methods for setting and getting individual values.  Generally an
 * empty container will be passed to a source which will fill in all the values,
 * and then the container will be passed along to a destination which will read out
 * the values.
 */

        #define LXu_VALUEARRAY		"6DAC2F05-D95B-11E8-9684-E200E9309701"
        #define LXa_VALUEARRAY		"valuearray"
        // [export] ILxValueArray va
        // [local]  ILxValueArray

        // [python] ILxValueArray:AddEmptyValue	obj Value
        // [python] ILxValueArray:GetValue	obj Value


        #define LXu_VALUEARRAY1		"A964962F-9028-4CA3-9612-17D360DF92BA"

/*
 * There is also this simple read-only list construct.  The elements are COM objects
 * that must be queried for their interface by the caller.  As usually, any returned
 * objects must be released by the caller.
 */

        #define LXu_ARRAY		"d1e1ba61-700e-48ad-aada-6865148fcc40"
        #define LXa_ARRAY		"array"

/*
 * The ILxScriptQuery interface allows scripts and other clients to easily and
 * generically access values from the internal systems.
 */

        #define LXu_SCRIPTQUERY		"0434F07E-AD4A-492f-AD43-3249BD16994D"
        #define LXa_SCRIPTQUERY		"scriptquery"
        // [export] ILxScriptQuery sq
        // [local]  ILxScriptQuery

/*
 * These error codes can be returned by the interface on error.
 */

        #define LXe_QUERY_UNKNOWN_SERVICE		LXxFAILCODE(LXeSYS_QUERY,0)
        #define LXe_QUERY_SERVICE_UNAVAILABLE		LXxFAILCODE(LXeSYS_QUERY,1)
        #define LXe_QUERY_UNKNOWN_ATTRIBUTE		LXxFAILCODE(LXeSYS_QUERY,2)
        #define LXe_QUERY_MISMATCHED_TYPE		LXxFAILCODE(LXeSYS_QUERY,3)
        #define LXe_QUERY_SELECT_FAILED			LXxFAILCODE(LXeSYS_QUERY,4)
        #define LXe_QUERY_NEED_SELECTION		LXxFAILCODE(LXeSYS_QUERY,5)
        #define LXe_QUERY_MISMATCHED_SELECTION		LXxFAILCODE(LXeSYS_QUERY,6)
        #define LXe_QUERY_NOT_APPLICABLE_TO_SELECTED	LXxFAILCODE(LXeSYS_QUERY,7)
        #define LXe_QUERY_ERROR				LXxFAILCODE(LXeSYS_QUERY,8)

/*
 * Many object types support tags, which are an opened-ended list of strings
 * indexed by numeric IDs.  Tags can be accessed using this interface.
 */

        #define LXu_STRINGTAG		"C2004BC7-6A90-4BD3-BDF7-B375C790DB70"
        // [local]  ILxStringTag
        // [export] ILxStringTag stag

/*
 * Some very common tags are defined here.
 */

        #define LXiTAG_COMMENT		 LXxID4('C','M','M','T')
        #define LXiTAG_DESCRIPTION	 LXxID4('D','E','S','C')
        #define LXiTAG_CUE		 LXxID4('C','U','E',' ')
        #define LXiTAG_LOCK		 LXxID4('L','O','C','K')


        #define LXu_MATRIX		"EF9FDE7B-E7FA-48B2-838E-A5A8F7D5C254"
        // [local]  ILxMatrix
        // [const]  ILxMatrix:Get3
        // [const]  ILxMatrix:Get4
        // [const]  ILxMatrix:GetOffset
        // [const]  ILxMatrix:MultiplyVector


        #define LXu_QUATERNION		"B8697DEB-DCD0-4C86-B822-702D5EDEFA76"
        // [local]  ILxQuaternion
        // [const]  ILxQuaternion:GetQuaternion
        // [const]  ILxQuaternion:GetMatrix
        // [const]  ILxQuaternion:GetAngleAxis


        #define LXa_VISITOR	"visitor"
        #define LXu_VISITOR	"C8FCAD70-DDDF-499E-A03B-A08B906D3E53"
        // [local]  ILxVisitor
        // [export] ILxVisitor

/*
 * Text encoding converts text encoding of multi-bytes international between UTF-8
 * and other encodings.
 * - LXiTEXT_ENCODING_DEFAULT
 * System default encoding. UTF-8 is for Linux, one of others are for Windows and
 * OSX and it is depended on the current locale setting.
 * - LXiTEXT_ENCODING_ANSI
 * ANSI character set for Latin.
 * 
 * - LXiTEXT_ENCODING_UTF8
 * UTF8
 * 
 * - LXiTEXT_ENCODING_SHIFTJIS
 * Shift-JIS (Japanese)
 * 
 * - LXiTEXT_ENCODING_EUCJP
 * EUC-JP (Japanese)
 * 
 * - LXiTEXT_ENCODING_EUCKR
 * EUC-KR (Korea KS C 5601)
 * 
 * - LXiTEXT_ENCODING_GB2312
 * GB2312 (Simplified Chinese)
 * 
 * - LXiTEXT_ENCODING_BIG5
 * BIG5 (Traditonal Chinese)
 * 
 */

        #define LXiTEXT_ENCODING_DEFAULT	0
        #define LXiTEXT_ENCODING_ANSI		1
        #define LXiTEXT_ENCODING_UTF8		2
        #define LXiTEXT_ENCODING_SHIFTJIS	3
        #define LXiTEXT_ENCODING_EUCJP		4
        #define LXiTEXT_ENCODING_EUCKR		5
        #define LXiTEXT_ENCODING_GB2312		6
        #define LXiTEXT_ENCODING_BIG5		7


        #define LXu_TEXTENCODING	"EE4989E5-F1E5-43D4-80CC-16F506EFD632"
        #define LXa_TEXTENCODING	"textencoding"
        // [local]  ILxTextEncoding


        #define LXu_TEXTENCODINGSERVICE	"7753B6E4-CF23-491E-89C1-2CA26BE5C89F"
        #define LXa_TEXTENCODINGSERVICE	"textencodingservice"
        // [python] ILxTextEncodingService:Allocate obj TextEncoding

#endif
