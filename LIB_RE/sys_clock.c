/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

_DWORD *__fastcall Close_Dev_Clock(int a1);
void __fastcall Open_Dev_Clock(int a1);
int __fastcall Sys_Clock_Init(int a1);
int __fastcall clock_set_pll_cpu(unsigned int a1);
int get_cpu_frequency();
int __fastcall read16(unsigned __int16 *a1);
int __fastcall read32(int a1);
__int64 __fastcall read64(int a1);
int __fastcall read8(unsigned __int8 *a1);
int __fastcall wait_pll_stable(int a1);
_WORD *__fastcall write16(_WORD *result, int a2, __int16 a3);
_DWORD *__fastcall write32(_DWORD *result, int a2, int a3);
_QWORD *__fastcall write64(_QWORD *result, int a2, __int64 a3);
_BYTE *__fastcall write8(_BYTE *result, int a2, char a3);
// int __fastcall delay_us(_DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

int cpu_frequency_hz = 0; // weak


//----- (00000000) --------------------------------------------------------
_DWORD *__fastcall Close_Dev_Clock(int a1)
{
  int v1; // r4
  int v2; // r10
  int v3; // r10

  v1 = a1;
  v2 = read32(4 * ((a1 >> 8) & 3) + 0x1C202C0);
  write32((_DWORD *)(4 * ((v1 >> 8) & 3) + 0x1C202C0), 0, v2 & ~(unsigned int)(1LL << (v1 & 0x1F)));
  v3 = read32(4 * ((v1 >> 8) & 3) + 0x1C20060);
  return write32((_DWORD *)(4 * ((v1 >> 8) & 3) + 0x1C20060), 0, v3 & ~(unsigned int)(1LL << (v1 & 0x1F)));
}

//----- (000000CC) --------------------------------------------------------
void __fastcall Open_Dev_Clock(int a1)
{
  int v1; // r4
  int v2; // r11
  int v3; // r11
  int v4; // ST00_4

  v1 = a1;
  v2 = read32(4 * ((a1 >> 8) & 3) + 0x1C20060);
  write32((_DWORD *)(4 * ((v1 >> 8) & 3) + 0x1C20060), 0, (unsigned __int64)(1LL << (v1 & 0x1F)) | v2);
  v3 = read32(4 * ((v1 >> 8) & 3) + 0x1C202C0);
  write32((_DWORD *)(4 * ((v1 >> 8) & 3) + 0x1C202C0), 0, v3 & ~(unsigned int)(1LL << (v1 & 0x1F)));
  delay_us(100);
  v4 = (unsigned __int64)(1LL << (v1 & 0x1F)) | read32(4 * ((v1 >> 8) & 3) + 0x1C202C0);
  write32((_DWORD *)(4 * ((v1 >> 8) & 3) + 0x1C202C0), 0, v4);
  delay_us(100);
}
// 4BC: using guessed type int __fastcall delay_us(_DWORD);

//----- (00000210) --------------------------------------------------------
int __fastcall Sys_Clock_Init(int a1)
{
  cpu_frequency_hz = 24000000 * (a1 / 24);
  write32((_DWORD *)0x1C20200, 0, 511);
  write32((_DWORD *)0x1C20204, 0, 511);
  write32((_DWORD *)0x1C20050, 0, 0x20000);
  write32((_DWORD *)0x1C20054, 0, 74000);
  return clock_set_pll_cpu(cpu_frequency_hz);
}
// 4AC: using guessed type int cpu_frequency_hz;

//----- (000002AC) --------------------------------------------------------
int __fastcall clock_set_pll_cpu(unsigned int a1)
{
  unsigned int v1; // r10
  unsigned int v2; // r5
  signed int v3; // r4
  signed int v4; // r6
  unsigned int v5; // r8
  int v6; // r0

  v1 = a1;
  if ( a1 > 0x2AEA5400 )
    v1 = 720000000;
  if ( v1 % 0x16E3600 )
  {
    if ( v1 % 0xB71B00 )
    {
      v2 = v1 / 0x16E3600 - 1;
      v3 = 0;
      v4 = 0;
    }
    else
    {
      v4 = 1;
      v5 = v1 / 0xB71B00;
      if ( v1 / 0xB71B00 % 3 )
      {
        if ( v5 & 3 )
          v3 = 1;
        else
          v3 = 3;
      }
      else
      {
        v3 = 2;
      }
      v2 = v5 / (v3 + 1) - 1;
    }
  }
  else
  {
    v2 = v1 / 0x16E3600 - 1;
    v3 = 0;
    v4 = 0;
  }
  v6 = read32(29491200);
  write32((_DWORD *)0x1C20000, 0, v6 & 0xFFFCE0CC | (v2 << 8) | 0x80000000 | 16 * v3 | v4);
  return wait_pll_stable(29491200);
}

//----- (000003F8) --------------------------------------------------------
int get_cpu_frequency()
{
  return cpu_frequency_hz;
}
// 4AC: using guessed type int cpu_frequency_hz;

//----- (00000408) --------------------------------------------------------
int __fastcall read16(unsigned __int16 *a1)
{
  return *a1;
}

//----- (00000418) --------------------------------------------------------
int __fastcall read32(int a1)
{
  return *(_DWORD *)a1;
}

//----- (00000428) --------------------------------------------------------
__int64 __fastcall read64(int a1)
{
  return *(_QWORD *)a1;
}

//----- (00000438) --------------------------------------------------------
int __fastcall read8(unsigned __int8 *a1)
{
  return *a1;
}

//----- (00000448) --------------------------------------------------------
int __fastcall wait_pll_stable(int a1)
{
  int v1; // r4
  signed int v2; // r5
  int result; // r0
  int v4; // r6

  v1 = a1;
  v2 = 4095;
  do
  {
    result = read32(v1);
    v4 = result;
    if ( !--v2 )
      break;
    result &= 0x10000000u;
  }
  while ( !(v4 & 0x10000000) );
  return result;
}

//----- (0000048C) --------------------------------------------------------
_WORD *__fastcall write16(_WORD *result, int a2, __int16 a3)
{
  *result = a3;
  return result;
}

//----- (00000494) --------------------------------------------------------
_DWORD *__fastcall write32(_DWORD *result, int a2, int a3)
{
  *result = a3;
  return result;
}

//----- (0000049C) --------------------------------------------------------
_QWORD *__fastcall write64(_QWORD *result, int a2, __int64 a3)
{
  *result = a3;
  return result;
}

//----- (000004A4) --------------------------------------------------------
_BYTE *__fastcall write8(_BYTE *result, int a2, char a3)
{
  *result = a3;
  return result;
}

// ALL OK, 14 function(s) have been successfully decompiled
