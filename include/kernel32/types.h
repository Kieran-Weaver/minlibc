#ifndef KERNEL32_TYPES_H
#define KERNEL32_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	unsigned long * Internal;
	unsigned long * InternalHigh;
	union {
		struct {
			uint32_t Offset;
			uint32_t OffsetHigh;
		} __temp_t;
		void* Pointer;
	} __temp_u;
	void* hEvent;
} overlapped_t;

typedef struct{
	void* Buffer;
	unsigned long long Alignment;
} file_segment_element_t;

typedef struct {
	uint32_t nLength;
	void* lpSecurityDescriptor;
	int bInheritHandle;
} security_attributes_t;

typedef struct {
	void* hProcess;
	void* hThread;
	uint32_t dwProcessId;
	uint32_t dwThreadId;
} process_info_t;

typedef struct {
	unsigned long long ReadOperationCount;
	unsigned long long WriteOperationCount;
	unsigned long long OtherOperationCount;
	unsigned long long ReadTransferCount;
	unsigned long long WriteTransferCount;
	unsigned long long OtherTransferCount;
} io_counters_t;

typedef struct {
	uint32_t  cb;
	char*  lpReserved;
	char*  lpDesktop;
	char*  lpTitle;
	uint32_t  dwX;
	uint32_t  dwY;
	uint32_t  dwXSize;
	uint32_t  dwYSize;
	uint32_t  dwXCountChars;
	uint32_t  dwYCountChars;
	uint32_t  dwFillAttribute;
	uint32_t  dwFlags;
	uint16_t   wShowWindow;
	uint16_t   cbReserved2;
	char* lpReserved2;
	void* hStdInput;
	void* hStdOutput;
	void* hStdError;
} startup_info_t;

typedef struct {
  void* lpData;
  uint32_t cbData;
  uint8_t  cbOverhead;
  uint8_t  iRegionIndex;
  uint16_t  wFlags;
  union {
    struct {
      void* hMem;
      uint32_t  dwReserved[3];
    } Block;
    struct {
      uint32_t  dwCommittedSize;
      uint32_t  dwUnCommittedSize;
      void* lpFirstBlock;
      void* lpLastBlock;
    } Region;
  } DUMMYUNIONNAME;
} process_heap_entry_t;

typedef struct {
  uint32_t  cb;
  size_t cbAllocated;
  size_t cbCommitted;
  size_t cbReserved;
  size_t cbMaxReserve;
} heap_summary_t;

typedef struct{
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} filetime_t;

typedef struct {
	uint16_t wYear;
	uint16_t wMonth;
	uint16_t wDayOfWeek;
	uint16_t wDay;
	uint16_t wHour;
	uint16_t wMinute;
	uint16_t wSecond;
	uint16_t wMilliseconds;
} systemtime_t;

typedef struct {
	long Bias;
	uint16_t StandardName[32];
	systemtime_t StandardDate;
	long StandardBias;
	uint16_t DaylightName[32];
	systemtime_t DaylightDate;
	long DaylightBias;
} tzinfo_t;

typedef struct {
	int bSetFocus;
} focus_event_record_t;

typedef struct {
	int bKeyDown;
	uint16_t wRepeatCount;
	uint16_t wVirtualKeyCode;
	uint16_t wVirtualScanCode;
	union {
		uint16_t UnicodeChar;
		char AsciiChar;
	} uChar;
	uint32_t dwControlKeyState;
} key_event_record_t;

typedef struct {
	unsigned int dwCommandId;
} menu_event_record_t;

typedef struct {
	short X;
	short Y;
} coord_t;

typedef struct {
	coord_t dwMousePosition;
	uint32_t dwButtonState;
	uint32_t dwControlKeyState;
	uint32_t dwEventFlags;
} mouse_event_record_t;

typedef struct {
	coord_t dwSize;
} window_buffer_size_record_t;

typedef struct {
	uint16_t EventType;
	union {
		key_event_record_t KeyEvent;
		mouse_event_record_t MouseEvent;
		window_buffer_size_record_t WindowBufferSizeEvent;
		menu_event_record_t MenuEvent;
		focus_event_record_t FocusEvent;
	} Event;
} input_record_t;

typedef struct {
	union {
		uint16_t UnicodeChar;
		char AsciiChar;
	} Char;
	uint16_t Attributes;
} char_info_t;

typedef struct {
	short Left;
	short Top;
	short Right;
	short Bottom;
} small_rect_t;

typedef struct {
	uint32_t dwSize;
	int bVisible;
} console_cursor_info_t;

typedef struct {
	uint32_t nFont;
	coord_t dwFontSize;
} console_font_info_t;

typedef struct {
	uint32_t dwFlags;
	coord_t dwSelectionAnchor;
	small_rect_t srSelection;
} console_selection_info_t;

typedef struct {
	coord_t dwSize;
	coord_t dwCursorPosition;
	uint16_t wAttributes;
	small_rect_t srWindow;
	coord_t dwMaximumWindowSize;
} console_screen_buffer_info_t;

typedef struct {
	uint32_t dwFileAttributes;
	filetime_t ftCreationTime;
	filetime_t ftLastAccessTime;
	filetime_t ftLastWriteTime;
	uint32_t dwVolumeSerialNumber;
	uint32_t nFileSizeHigh;
	uint32_t nFileSizeLow;
	uint32_t nNumberOfLinks;
	uint32_t nFileIndexHigh;
	uint32_t nFileIndexLow;
} by_handle_file_information_t;

typedef enum {
	GetFileExInfoStandard,
	GetFileExMaxInfoLevel
} get_fileex_info_levels_e;

typedef int (*handler_routine_t)(uint32_t);
typedef uint32_t (*progress_routine_t)(uint64_t, uint64_t, uint64_t, uint64_t, uint32_t, uint32_t, void*, void*, void*);
typedef void (*overlapped_completion_routine_t)(uint32_t, uint32_t, overlapped_t*);
typedef void (*_wait_or_timer_callback)(void*, int);

#ifdef __cplusplus
}
#endif

#endif
