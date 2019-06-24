#pragma once

#include "easyhook.h"

typedef struct _HOOK_ACL_
{
	ULONG                   Count;
	BOOL                    IsExclusive;
	ULONG                   Entries[MAX_ACE_COUNT];
}HOOK_ACL;

typedef struct _LOCAL_HOOK_INFO_
{
	PLOCAL_HOOK_INFO        Next;
	ULONG					NativeSize;
	UCHAR* TargetProc;
	ULONGLONG				TargetBackup;
	ULONGLONG				TargetBackup_x64;
	ULONGLONG				HookCopy;
	ULONG					EntrySize;
	UCHAR* Trampoline;
	ULONG					HLSIndex;
	ULONG					HLSIdent;
	void* Callback;
	HOOK_ACL				LocalACL;
	ULONG                   Signature;
	TRACED_HOOK_HANDLE      Tracking;

	void* RandomValue; // fixed
	void* HookIntro; // fixed
	UCHAR* OldProc; // fixed
	UCHAR* HookProc; // fixed
	void* HookOutro; // fixed
	int* IsExecutedPtr; // fixed
}LOCAL_HOOK_INFO, * PLOCAL_HOOK_INFO;
