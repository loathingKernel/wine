/* IDirectMusicBuffer Implementation
 *
 * Copyright (C) 2003-2004 Rok Mandeljc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "dmusic_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(dmusic);

/* IDirectMusicBufferImpl IUnknown part: */
HRESULT WINAPI IDirectMusicBufferImpl_QueryInterface (LPDIRECTMUSICBUFFER iface, REFIID riid, LPVOID *ppobj) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	TRACE("(%p, (%s, %p)\n",This,debugstr_dmguid(riid),ppobj);
	if (IsEqualIID (riid, &IID_IUnknown) 
		|| IsEqualIID (riid, &IID_IDirectMusicBuffer)) {
		IDirectMusicBufferImpl_AddRef(iface);
		*ppobj = This;
		return S_OK;
	}
	WARN("(%p, (%s, %p): not found\n",This,debugstr_dmguid(riid),ppobj);
	return E_NOINTERFACE;
}

ULONG WINAPI IDirectMusicBufferImpl_AddRef (LPDIRECTMUSICBUFFER iface) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	ULONG refCount = InterlockedIncrement(&This->ref);

	TRACE("(%p)->(ref before=%lu)\n", This, refCount - 1);

	DMUSIC_LockModule();

	return refCount;
}

ULONG WINAPI IDirectMusicBufferImpl_Release (LPDIRECTMUSICBUFFER iface) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	ULONG refCount = InterlockedDecrement(&This->ref);

	TRACE("(%p)->(ref before=%lu)\n", This, refCount + 1);

	if (!refCount) {
		HeapFree(GetProcessHeap(), 0, This);
	}

	DMUSIC_UnlockModule();
	
	return refCount;
}

/* IDirectMusicBufferImpl IDirectMusicBuffer part: */
HRESULT WINAPI IDirectMusicBufferImpl_Flush (LPDIRECTMUSICBUFFER iface) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p): stub\n", This);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_TotalTime (LPDIRECTMUSICBUFFER iface, LPREFERENCE_TIME prtTime) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, prtTime);	
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_PackStructured (LPDIRECTMUSICBUFFER iface, REFERENCE_TIME rt, DWORD dwChannelGroup, DWORD dwChannelMessage) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %lli, %ld, %ld): stub\n", This, rt, dwChannelGroup, dwChannelMessage);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_PackUnstructured (LPDIRECTMUSICBUFFER iface, REFERENCE_TIME rt, DWORD dwChannelGroup, DWORD cb, LPBYTE lpb) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %lli, %ld, %ld, %p): stub\n", This, rt, dwChannelGroup, cb, lpb);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_ResetReadPtr (LPDIRECTMUSICBUFFER iface) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p): stub\n", This);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetNextEvent (LPDIRECTMUSICBUFFER iface, LPREFERENCE_TIME prt, LPDWORD pdwChannelGroup, LPDWORD pdwLength, LPBYTE* ppData) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p, %p, %p, %p): stub\n", This, prt, pdwChannelGroup, pdwLength, ppData);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetRawBufferPtr (LPDIRECTMUSICBUFFER iface, LPBYTE* ppData) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, ppData);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetStartTime (LPDIRECTMUSICBUFFER iface, LPREFERENCE_TIME prt) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, prt);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetUsedBytes (LPDIRECTMUSICBUFFER iface, LPDWORD pcb) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, pcb);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetMaxBytes (LPDIRECTMUSICBUFFER iface, LPDWORD pcb) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, pcb);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_GetBufferFormat (LPDIRECTMUSICBUFFER iface, LPGUID pGuidFormat) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %p): stub\n", This, pGuidFormat);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_SetStartTime (LPDIRECTMUSICBUFFER iface, REFERENCE_TIME rt) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %lli): stub\n", This, rt);
	return S_OK;
}

HRESULT WINAPI IDirectMusicBufferImpl_SetUsedBytes (LPDIRECTMUSICBUFFER iface, DWORD cb) {
	IDirectMusicBufferImpl *This = (IDirectMusicBufferImpl *)iface;
	FIXME("(%p, %ld): stub\n", This, cb);
	return S_OK;
}

IDirectMusicBufferVtbl DirectMusicBuffer_Vtbl = {
	IDirectMusicBufferImpl_QueryInterface,
	IDirectMusicBufferImpl_AddRef,
	IDirectMusicBufferImpl_Release,
	IDirectMusicBufferImpl_Flush,
	IDirectMusicBufferImpl_TotalTime,
	IDirectMusicBufferImpl_PackStructured,
	IDirectMusicBufferImpl_PackUnstructured,
	IDirectMusicBufferImpl_ResetReadPtr,
	IDirectMusicBufferImpl_GetNextEvent,
	IDirectMusicBufferImpl_GetRawBufferPtr,
	IDirectMusicBufferImpl_GetStartTime,
	IDirectMusicBufferImpl_GetUsedBytes,
	IDirectMusicBufferImpl_GetMaxBytes,
	IDirectMusicBufferImpl_GetBufferFormat,
	IDirectMusicBufferImpl_SetStartTime,
	IDirectMusicBufferImpl_SetUsedBytes
};

/* for ClassFactory */
HRESULT WINAPI DMUSIC_CreateDirectMusicBufferImpl (LPCGUID lpcGUID, LPVOID* ppobj, LPUNKNOWN pUnkOuter) {
	IDirectMusicBufferImpl* dmbuff;
	
	dmbuff = HeapAlloc (GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(IDirectMusicBufferImpl));
	if (NULL == dmbuff) {
		*ppobj = NULL;
		return E_OUTOFMEMORY;
	}
	dmbuff->lpVtbl = &DirectMusicBuffer_Vtbl;
	dmbuff->ref = 0; /* will be inited by QueryInterface */
	
	return IDirectMusicBufferImpl_QueryInterface ((LPDIRECTMUSICBUFFER)dmbuff, lpcGUID, ppobj);
}
