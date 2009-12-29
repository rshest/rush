#ifndef __PARAMTYPE__
#define __PARAMTYPE__

// Parameter types
//    several of these types fold to the same underlying value type but provide
//    either a more complete description of the type or imply non-standard dimensions that are
//    automatically applied.

#define TYPE_TAB	0x0800		// flags the type as a Tab<>
// following bits for FnPub use only
#define TYPE_BY_REF	0x1000		// flags the parameter as being delivered by reference (&)
#define TYPE_BY_VAL	0x2000		// flags the parameter as being delivered by value (via a local copy owned by the FPValue)
#define TYPE_BY_PTR	0x4000		// flags the parameter as being delivered by pointer (*)

// Built in data types
enum ParamType {
	TYPE_FLOAT,
	TYPE_INT,
	TYPE_RGBA,
	TYPE_POINT3,
	TYPE_BOOL,

	// We can add types up to 32 total.
	TYPE_USER,
	};

enum ParamType2 
{
 // TYPE_FLOAT,  // these are defined in original ParamType...
 // TYPE_INT,
 // TYPE_RGBA,
 // TYPE_POINT3,
 // TYPE_BOOL,
	TYPE_ANGLE = TYPE_BOOL + 1,
	TYPE_PCNT_FRAC,
	TYPE_WORLD,
	TYPE_STRING,
	TYPE_FILENAME,
	TYPE_HSV,
	TYPE_COLOR_CHANNEL,
	TYPE_TIMEVALUE,
	TYPE_RADIOBTN_INDEX,
	TYPE_MTL,
	TYPE_TEXMAP,
	TYPE_BITMAP,
	TYPE_INODE,
	TYPE_REFTARG,
	// new for R4...
	TYPE_INDEX,
	TYPE_MATRIX3,
	TYPE_PBLOCK2,
	// new for R6...
	TYPE_POINT4,
	TYPE_FRGBA,

	// only for published function parameter types, not pblock2 parameter types...
	TYPE_ENUM,
	TYPE_VOID,
	TYPE_INTERVAL,
	TYPE_ANGAXIS,
	TYPE_QUAT,
	TYPE_RAY,
	TYPE_POINT2,
	TYPE_BITARRAY,
	TYPE_CLASS,
	TYPE_MESH,
	TYPE_OBJECT,
	TYPE_CONTROL,
	TYPE_POINT,
	TYPE_TSTR,
	TYPE_IOBJECT,
	TYPE_INTERFACE,
	TYPE_HWND,
	TYPE_NAME,
	TYPE_COLOR,
	TYPE_FPVALUE,
	TYPE_VALUE,
	TYPE_DWORD,
	TYPE_bool,
	TYPE_INTPTR,
	TYPE_INT64,
	TYPE_DOUBLE,

	// Tab<>s of above  (MUST be in same order as base types)
	TYPE_FLOAT_TAB = TYPE_FLOAT + TYPE_TAB,
	TYPE_INT_TAB,
	TYPE_RGBA_TAB,
	TYPE_POINT3_TAB,
	TYPE_BOOL_TAB,
	TYPE_ANGLE_TAB,
	TYPE_PCNT_FRAC_TAB,
	TYPE_WORLD_TAB,
	TYPE_STRING_TAB,
	TYPE_FILENAME_TAB,
	TYPE_HSV_TAB,
	TYPE_COLOR_CHANNEL_TAB,
	TYPE_TIMEVALUE_TAB,
	TYPE_RADIOBTN_INDEX_TAB,
	TYPE_MTL_TAB,
	TYPE_TEXMAP_TAB,
	TYPE_BITMAP_TAB,
	TYPE_INODE_TAB,
	TYPE_REFTARG_TAB,
	// new for R4...
	TYPE_INDEX_TAB,
	TYPE_MATRIX3_TAB,
	TYPE_PBLOCK2_TAB,
	// new for R6...
	TYPE_POINT4_TAB,
	TYPE_FRGBA_TAB,

	// only for published function parameter types, not pblock2 parameter types...
	TYPE_ENUM_TAB,
	TYPE_VOID_TAB,
	TYPE_INTERVAL_TAB,
	TYPE_ANGAXIS_TAB,
	TYPE_QUAT_TAB,
	TYPE_RAY_TAB,
	TYPE_POINT2_TAB,
	TYPE_BITARRAY_TAB,
	TYPE_CLASS_TAB,
	TYPE_MESH_TAB,
	TYPE_OBJECT_TAB,
	TYPE_CONTROL_TAB,
	TYPE_POINT_TAB,
	TYPE_TSTR_TAB,
	TYPE_IOBJECT_TAB,
	TYPE_INTERFACE_TAB,
	TYPE_HWND_TAB,
	TYPE_NAME_TAB,
	TYPE_COLOR_TAB,
	TYPE_FPVALUE_TAB,
	TYPE_VALUE_TAB,
	TYPE_DWORD_TAB,
	TYPE_bool_TAB,
	TYPE_INTPTR_TAB,
	TYPE_INT64_TAB,
	TYPE_DOUBLE_TAB,

	// pass by-ref types, implies & parameters, int& & float& are passed via .ptr fields, only for FnPub use
	TYPE_FLOAT_BR					= TYPE_FLOAT + TYPE_BY_REF,
	TYPE_INT_BR						= TYPE_INT + TYPE_BY_REF,
	TYPE_BOOL_BR 					= TYPE_BOOL + TYPE_BY_REF,
	TYPE_ANGLE_BR 					= TYPE_ANGLE + TYPE_BY_REF,
	TYPE_PCNT_FRAC_BR 				= TYPE_PCNT_FRAC + TYPE_BY_REF,
	TYPE_WORLD_BR 					= TYPE_WORLD + TYPE_BY_REF,
	TYPE_COLOR_CHANNEL_BR 			= TYPE_COLOR_CHANNEL + TYPE_BY_REF,
	TYPE_TIMEVALUE_BR 				= TYPE_TIMEVALUE + TYPE_BY_REF,
	TYPE_RADIOBTN_INDEX_BR 			= TYPE_RADIOBTN_INDEX + TYPE_BY_REF,
	TYPE_INDEX_BR 					= TYPE_INDEX + TYPE_BY_REF,
	TYPE_RGBA_BR 					= TYPE_RGBA + TYPE_BY_REF,
	TYPE_BITMAP_BR 					= TYPE_BITMAP + TYPE_BY_REF,
	TYPE_POINT3_BR 					= TYPE_POINT3 + TYPE_BY_REF,
	TYPE_HSV_BR 					= TYPE_HSV + TYPE_BY_REF,
	TYPE_REFTARG_BR 				= TYPE_REFTARG + TYPE_BY_REF,
	TYPE_MATRIX3_BR 				= TYPE_MATRIX3 + TYPE_BY_REF,
	TYPE_POINT4_BR 					= TYPE_POINT4 + TYPE_BY_REF,
	TYPE_FRGBA_BR 					= TYPE_FRGBA + TYPE_BY_REF,
	TYPE_ENUM_BR 					= TYPE_ENUM + TYPE_BY_REF,
	TYPE_INTERVAL_BR 				= TYPE_INTERVAL + TYPE_BY_REF,
	TYPE_ANGAXIS_BR 				= TYPE_ANGAXIS + TYPE_BY_REF,
	TYPE_QUAT_BR 					= TYPE_QUAT + TYPE_BY_REF,
	TYPE_RAY_BR 					= TYPE_RAY + TYPE_BY_REF,
	TYPE_POINT2_BR 					= TYPE_POINT2 + TYPE_BY_REF,
	TYPE_BITARRAY_BR 				= TYPE_BITARRAY + TYPE_BY_REF,
	TYPE_MESH_BR 					= TYPE_MESH + TYPE_BY_REF,
	TYPE_POINT_BR 					= TYPE_POINT + TYPE_BY_REF,
	TYPE_TSTR_BR 					= TYPE_TSTR + TYPE_BY_REF,
	TYPE_COLOR_BR 					= TYPE_COLOR + TYPE_BY_REF,
	TYPE_FPVALUE_BR 				= TYPE_FPVALUE + TYPE_BY_REF,
	TYPE_DWORD_BR 					= TYPE_DWORD + TYPE_BY_REF,
	TYPE_bool_BR 					= TYPE_bool + TYPE_BY_REF,
	TYPE_INTPTR_BR					= TYPE_INTPTR + TYPE_BY_REF,
	TYPE_INT64_BR					= TYPE_INT64 + TYPE_BY_REF,
	TYPE_DOUBLE_BR					= TYPE_DOUBLE + TYPE_BY_REF,

	// pass by-ref Tab<> types - tab is passed by ref, data type in tab is TYPE_XXXX.
	// For example: TYPE_FLOAT_TAB_BR = Tab<float>& , TYPE_INODE_TAB_BR_TYPE = Tab<INode*>&
	TYPE_FLOAT_TAB_BR				= TYPE_FLOAT + TYPE_TAB + TYPE_BY_REF,
	TYPE_INT_TAB_BR					= TYPE_INT + TYPE_TAB + TYPE_BY_REF,
	TYPE_RGBA_TAB_BR				= TYPE_RGBA + TYPE_TAB + TYPE_BY_REF,
	TYPE_POINT3_TAB_BR				= TYPE_POINT3 + TYPE_TAB + TYPE_BY_REF,
	TYPE_BOOL_TAB_BR				= TYPE_BOOL + TYPE_TAB + TYPE_BY_REF,
	TYPE_ANGLE_TAB_BR				= TYPE_ANGLE + TYPE_TAB + TYPE_BY_REF,
	TYPE_PCNT_FRAC_TAB_BR			= TYPE_PCNT_FRAC + TYPE_TAB + TYPE_BY_REF,
	TYPE_WORLD_TAB_BR				= TYPE_WORLD + TYPE_TAB + TYPE_BY_REF,
	TYPE_STRING_TAB_BR				= TYPE_STRING + TYPE_TAB + TYPE_BY_REF,
	TYPE_FILENAME_TAB_BR			= TYPE_FILENAME + TYPE_TAB + TYPE_BY_REF,
	TYPE_HSV_TAB_BR					= TYPE_HSV + TYPE_TAB + TYPE_BY_REF,
	TYPE_COLOR_CHANNEL_TAB_BR		= TYPE_COLOR_CHANNEL + TYPE_TAB + TYPE_BY_REF,
	TYPE_TIMEVALUE_TAB_BR			= TYPE_TIMEVALUE + TYPE_TAB + TYPE_BY_REF,
	TYPE_RADIOBTN_INDEX_TAB_BR		= TYPE_RADIOBTN_INDEX + TYPE_TAB + TYPE_BY_REF,
	TYPE_MTL_TAB_BR					= TYPE_MTL + TYPE_TAB + TYPE_BY_REF,
	TYPE_TEXMAP_TAB_BR				= TYPE_TEXMAP + TYPE_TAB + TYPE_BY_REF,
	TYPE_BITMAP_TAB_BR				= TYPE_BITMAP + TYPE_TAB + TYPE_BY_REF,
	TYPE_INODE_TAB_BR				= TYPE_INODE + TYPE_TAB + TYPE_BY_REF,
	TYPE_REFTARG_TAB_BR				= TYPE_REFTARG + TYPE_TAB + TYPE_BY_REF,
	TYPE_INDEX_TAB_BR				= TYPE_INDEX + TYPE_TAB + TYPE_BY_REF,
	TYPE_MATRIX3_TAB_BR				= TYPE_MATRIX3 + TYPE_TAB + TYPE_BY_REF,
	TYPE_POINT4_TAB_BR 				= TYPE_POINT4 + TYPE_TAB + TYPE_BY_REF,
	TYPE_FRGBA_TAB_BR 				= TYPE_FRGBA + TYPE_TAB + TYPE_BY_REF,
	TYPE_TSTR_TAB_BR				= TYPE_TSTR + TYPE_TAB + TYPE_BY_REF,
	TYPE_ENUM_TAB_BR				= TYPE_ENUM + TYPE_TAB + TYPE_BY_REF,
	TYPE_INTERVAL_TAB_BR			= TYPE_INTERVAL + TYPE_TAB + TYPE_BY_REF,
	TYPE_ANGAXIS_TAB_BR				= TYPE_ANGAXIS + TYPE_TAB + TYPE_BY_REF,
	TYPE_QUAT_TAB_BR				= TYPE_QUAT + TYPE_TAB + TYPE_BY_REF,
	TYPE_RAY_TAB_BR					= TYPE_RAY + TYPE_TAB + TYPE_BY_REF,
	TYPE_POINT2_TAB_BR				= TYPE_POINT2 + TYPE_TAB + TYPE_BY_REF,
	TYPE_BITARRAY_TAB_BR			= TYPE_BITARRAY + TYPE_TAB + TYPE_BY_REF,
	TYPE_CLASS_TAB_BR				= TYPE_CLASS + TYPE_TAB + TYPE_BY_REF,
	TYPE_MESH_TAB_BR				= TYPE_MESH + TYPE_TAB + TYPE_BY_REF,
	TYPE_OBJECT_TAB_BR				= TYPE_OBJECT + TYPE_TAB + TYPE_BY_REF,
	TYPE_CONTROL_TAB_BR				= TYPE_CONTROL + TYPE_TAB + TYPE_BY_REF,
	TYPE_POINT_TAB_BR				= TYPE_POINT + TYPE_TAB + TYPE_BY_REF,
	TYPE_IOBJECT_TAB_BR				= TYPE_IOBJECT + TYPE_TAB + TYPE_BY_REF,
	TYPE_INTERFACE_TAB_BR			= TYPE_INTERFACE + TYPE_TAB + TYPE_BY_REF,
	TYPE_HWND_TAB_BR				= TYPE_HWND + TYPE_TAB + TYPE_BY_REF,
	TYPE_NAME_TAB_BR				= TYPE_NAME + TYPE_TAB + TYPE_BY_REF,
	TYPE_COLOR_TAB_BR				= TYPE_COLOR + TYPE_TAB + TYPE_BY_REF,
	TYPE_FPVALUE_TAB_BR				= TYPE_FPVALUE + TYPE_TAB + TYPE_BY_REF,
	TYPE_VALUE_TAB_BR				= TYPE_VALUE + TYPE_TAB + TYPE_BY_REF,
	TYPE_DWORD_TAB_BR				= TYPE_DWORD + TYPE_TAB + TYPE_BY_REF,
	TYPE_bool_TAB_BR				= TYPE_bool + TYPE_TAB + TYPE_BY_REF,
	TYPE_INTPTR_TAB_BR				= TYPE_INTPTR + TYPE_TAB + TYPE_BY_REF,
	TYPE_INT64_TAB_BR				= TYPE_INT64 + TYPE_TAB + TYPE_BY_REF,
	TYPE_DOUBLE_TAB_BR				= TYPE_DOUBLE + TYPE_TAB + TYPE_BY_REF,

	// pass by-value types, implies dereferencing the (meaningful) pointer-based values, only for FnPub use
	TYPE_RGBA_BV					= TYPE_RGBA + TYPE_BY_VAL,
	TYPE_POINT3_BV					= TYPE_POINT3 + TYPE_BY_VAL,
	TYPE_HSV_BV						= TYPE_HSV + TYPE_BY_VAL,
	TYPE_INTERVAL_BV				= TYPE_INTERVAL + TYPE_BY_VAL,
	TYPE_BITMAP_BV					= TYPE_BITMAP + TYPE_BY_VAL,
	TYPE_MATRIX3_BV					= TYPE_MATRIX3 + TYPE_BY_VAL,
	TYPE_POINT4_BV 					= TYPE_POINT4 + TYPE_BY_VAL,
	TYPE_FRGBA_BV 					= TYPE_FRGBA + TYPE_BY_VAL,
	TYPE_ANGAXIS_BV					= TYPE_ANGAXIS + TYPE_BY_VAL,
	TYPE_QUAT_BV					= TYPE_QUAT + TYPE_BY_VAL,
	TYPE_RAY_BV						= TYPE_RAY + TYPE_BY_VAL,
	TYPE_POINT2_BV					= TYPE_POINT2 + TYPE_BY_VAL,
	TYPE_BITARRAY_BV				= TYPE_BITARRAY + TYPE_BY_VAL,
	TYPE_MESH_BV					= TYPE_MESH + TYPE_BY_VAL,
	TYPE_POINT_BV					= TYPE_POINT + TYPE_BY_VAL,
	TYPE_TSTR_BV					= TYPE_TSTR + TYPE_BY_VAL,
	TYPE_COLOR_BV					= TYPE_COLOR + TYPE_BY_VAL,
	TYPE_FPVALUE_BV					= TYPE_FPVALUE + TYPE_BY_VAL,
	TYPE_CLASS_BV					= TYPE_CLASS + TYPE_BY_VAL,

	// pass by-val Tab<> types - tab is passed by val, data type in tab is TYPE_XXXX.
	// For example: TYPE_FLOAT_TAB_BV = Tab<float> , TYPE_INODE_TAB_BV = Tab<INode*>
	TYPE_FLOAT_TAB_BV				= TYPE_FLOAT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INT_TAB_BV					= TYPE_INT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_RGBA_TAB_BV				= TYPE_RGBA + TYPE_TAB + TYPE_BY_VAL,
	TYPE_POINT3_TAB_BV				= TYPE_POINT3 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_BOOL_TAB_BV				= TYPE_BOOL + TYPE_TAB + TYPE_BY_VAL,
	TYPE_ANGLE_TAB_BV				= TYPE_ANGLE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_PCNT_FRAC_TAB_BV			= TYPE_PCNT_FRAC + TYPE_TAB + TYPE_BY_VAL,
	TYPE_WORLD_TAB_BV				= TYPE_WORLD + TYPE_TAB + TYPE_BY_VAL,
	TYPE_STRING_TAB_BV				= TYPE_STRING + TYPE_TAB + TYPE_BY_VAL,
	TYPE_FILENAME_TAB_BV			= TYPE_FILENAME + TYPE_TAB + TYPE_BY_VAL,
	TYPE_HSV_TAB_BV					= TYPE_HSV + TYPE_TAB + TYPE_BY_VAL,
	TYPE_COLOR_CHANNEL_TAB_BV		= TYPE_COLOR_CHANNEL + TYPE_TAB + TYPE_BY_VAL,
	TYPE_TIMEVALUE_TAB_BV			= TYPE_TIMEVALUE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_RADIOBTN_INDEX_TAB_BV		= TYPE_RADIOBTN_INDEX + TYPE_TAB + TYPE_BY_VAL,
	TYPE_MTL_TAB_BV					= TYPE_MTL + TYPE_TAB + TYPE_BY_VAL,
	TYPE_TEXMAP_TAB_BV				= TYPE_TEXMAP + TYPE_TAB + TYPE_BY_VAL,
	TYPE_BITMAP_TAB_BV				= TYPE_BITMAP + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INODE_TAB_BV				= TYPE_INODE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_REFTARG_TAB_BV				= TYPE_REFTARG + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INDEX_TAB_BV				= TYPE_INDEX + TYPE_TAB + TYPE_BY_VAL,
	TYPE_MATRIX3_TAB_BV				= TYPE_MATRIX3 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_POINT4_TAB_BV 				= TYPE_POINT4 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_FRGBA_TAB_BV 				= TYPE_FRGBA + TYPE_TAB + TYPE_BY_VAL,
	TYPE_PBLOCK2_TAB_BV				= TYPE_PBLOCK2 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_VOID_TAB_BV				= TYPE_VOID + TYPE_TAB + TYPE_BY_VAL,
	TYPE_TSTR_TAB_BV				= TYPE_TSTR + TYPE_TAB + TYPE_BY_VAL,
	TYPE_ENUM_TAB_BV				= TYPE_ENUM + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INTERVAL_TAB_BV			= TYPE_INTERVAL + TYPE_TAB + TYPE_BY_VAL,
	TYPE_ANGAXIS_TAB_BV				= TYPE_ANGAXIS + TYPE_TAB + TYPE_BY_VAL,
	TYPE_QUAT_TAB_BV				= TYPE_QUAT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_RAY_TAB_BV					= TYPE_RAY + TYPE_TAB + TYPE_BY_VAL,
	TYPE_POINT2_TAB_BV				= TYPE_POINT2 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_BITARRAY_TAB_BV			= TYPE_BITARRAY + TYPE_TAB + TYPE_BY_VAL,
	TYPE_CLASS_TAB_BV				= TYPE_CLASS + TYPE_TAB + TYPE_BY_VAL,
	TYPE_MESH_TAB_BV				= TYPE_MESH + TYPE_TAB + TYPE_BY_VAL,
	TYPE_OBJECT_TAB_BV				= TYPE_OBJECT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_CONTROL_TAB_BV				= TYPE_CONTROL + TYPE_TAB + TYPE_BY_VAL,
	TYPE_POINT_TAB_BV				= TYPE_POINT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_IOBJECT_TAB_BV				= TYPE_IOBJECT + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INTERFACE_TAB_BV			= TYPE_INTERFACE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_HWND_TAB_BV				= TYPE_HWND + TYPE_TAB + TYPE_BY_VAL,
	TYPE_NAME_TAB_BV				= TYPE_NAME + TYPE_TAB + TYPE_BY_VAL,
	TYPE_COLOR_TAB_BV				= TYPE_COLOR + TYPE_TAB + TYPE_BY_VAL,
	TYPE_FPVALUE_TAB_BV				= TYPE_FPVALUE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_VALUE_TAB_BV				= TYPE_VALUE + TYPE_TAB + TYPE_BY_VAL,
	TYPE_DWORD_TAB_BV				= TYPE_DWORD + TYPE_TAB + TYPE_BY_VAL,
	TYPE_bool_TAB_BV				= TYPE_bool + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INTPTR_TAB_BV				= TYPE_INTPTR + TYPE_TAB + TYPE_BY_VAL,
	TYPE_INT64_TAB_BV				= TYPE_INT64 + TYPE_TAB + TYPE_BY_VAL,
	TYPE_DOUBLE_TAB_BV				= TYPE_DOUBLE + TYPE_TAB + TYPE_BY_VAL,

	// pass by-pointer types for int & float types, implies * parameters, int* & float* are passed via .ptr fields, only for FnPub use
	TYPE_FLOAT_BP					= TYPE_FLOAT + TYPE_BY_PTR,
	TYPE_INT_BP						= TYPE_INT + TYPE_BY_PTR,
	TYPE_BOOL_BP					= TYPE_BOOL + TYPE_BY_PTR,
	TYPE_ANGLE_BP					= TYPE_ANGLE + TYPE_BY_PTR,
	TYPE_PCNT_FRAC_BP				= TYPE_PCNT_FRAC + TYPE_BY_PTR,
	TYPE_WORLD_BP					= TYPE_WORLD + TYPE_BY_PTR,
	TYPE_COLOR_CHANNEL_BP			= TYPE_COLOR_CHANNEL + TYPE_BY_PTR,
	TYPE_TIMEVALUE_BP				= TYPE_TIMEVALUE + TYPE_BY_PTR,
	TYPE_RADIOBTN_INDEX_BP			= TYPE_RADIOBTN_INDEX + TYPE_BY_PTR,
	TYPE_INDEX_BP					= TYPE_INDEX + TYPE_BY_PTR,
	TYPE_ENUM_BP					= TYPE_ENUM + TYPE_BY_PTR,
	TYPE_DWORD_BP					= TYPE_DWORD + TYPE_BY_PTR,
	TYPE_bool_BP					= TYPE_bool + TYPE_BY_PTR,
	TYPE_INTPTR_BP					= TYPE_INTPTR + TYPE_BY_PTR,
	TYPE_INT64_BP					= TYPE_INT64 + TYPE_BY_PTR,
	TYPE_DOUBLE_BP					= TYPE_DOUBLE + TYPE_BY_PTR,

	// there are no specific by-pointer Tab<> types, all Tab<> types are by-pointer by default

	TYPE_MAX_TYPE,	
	
	// MAXScript internal types
	TYPE_KEYARG_MARKER = 253,
	TYPE_MSFLOAT,
	TYPE_UNSPECIFIED, 

};

// UI control types
#include <custcont.h>

enum ControlType {
	TYPE_SPINNER,
	TYPE_RADIO,
	TYPE_SINGLECHEKBOX,
	TYPE_MULTICHEKBOX,
	TYPE_COLORSWATCH,
	};

enum ControlType2
{
 // TYPE_SPINNER,	 these are defined in original ControlType...
 // TYPE_RADIO,
 // TYPE_SINGLECHEKBOX,
 // TYPE_MULTICHEKBOX,
 // TYPE_COLORSWATCH,
	TYPE_EDITBOX = TYPE_COLORSWATCH + 1,
	TYPE_CHECKBUTTON,
	TYPE_PICKNODEBUTTON,
	TYPE_TEXMAPBUTTON,
	TYPE_MTLBUTTON,
	TYPE_BITMAPBUTTON,
	TYPE_FILEOPENBUTTON,
	TYPE_FILESAVEBUTTON,
	TYPE_INTLISTBOX,
	TYPE_FLOATLISTBOX,
	TYPE_STRINGLISTBOX,
	TYPE_NODELISTBOX,
	TYPE_MAPLISTBOX,
// begin - mjm 12.19.98
	TYPE_SLIDER,
// end - mjm 12.19.98
	// new for R4
	TYPE_BUTTON,
	TYPE_POINT3LISTBOX, // nac 11.12.00
	TYPE_SHADERBUTTON_DEFUNCT,	// nac 02.26.02
	TYPE_CONNECTIONSHADERBUTTON_DEFUNCT,    // [dl | 13aug2002]
	TYPE_SHADERSUBPARAMETERBLOCK,   // [dl | 14aug2002]
	TYPE_POINT4LISTBOX, // LAM - 5/27/03
	TYPE_COLORSWATCH_FRGBA, // LAM - 5/27/03

	TYPE_INT_COMBOBOX , //Zhuofen  - 10-17-2007
};

// param definition optional info tags
enum ParamTags
{
	// make them large -ve for crude validation
	p_default = -(1<<30),		// default value (for UI creation)
	p_ms_default,				// default value when constructed by scripts 
	p_range,					// allowable ranges, used in MS validation and spinner/slider setup
	p_ui,						// associated UI rollout control IDs, etc., 
	p_validator,				// validator object
	p_accessor,					// accessor object
	p_vals,						// radio button values in button order if non-ordinal
//	p_subanim_order,			// overrides sequential subanim order
	p_refno,					// specifies reference # in owner for this reference param, base refo in case of a Tab<>
	p_subtexno,					// for Texmap items in Mtls, defines the SubText index for this Texmap in the owner Mtl
	p_submtlno,					// for Mtl items in Mtls, defines the SubMtl index for this Mtl in the owner Mtl
	p_dim,						// supply dimension for this parameter
	p_classID,					// class ID validator for the various reftarg params (used by scripter, picknode filter, etc.)
	p_sclassID,					// superclass ID "     "     "     "      "
	p_enabled,					// associated UI controls are disabled by default
	p_enable_ctrls,				// for TYPE_BOOLs, lists which other params would be automatically UI enabled/disabled by this param
	p_prompt,					// status line prompt string res ID for various picker buttons
	p_caption,					// caption string res ID for open/save file dlgs
	p_init_file,				// initial filename for open/save file dlgs
	p_file_types,				// file types string res ID for open/save file dlgs (in MAXScript type: form)
	p_ctrl_ids,					// <used internally> sets the ctrl_id array for the parameter
	// new for R4
	p_uix,						// map ID if param is in more than one map, can have more than one of these
	// new for R6
	p_configurable_default,		// default can be taken from .ini file.
	p_tooltip,				// ToolTip string resource identifier

	end = p_default + 1024,
	properties,
	enums,
};

#endif

