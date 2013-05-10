/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
                                        cpu12.gems@googlemail.com>

   All Rights Reserved

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   s. FLOSS-EXCEPTION.txt
 */
#if !defined(__OS_PORT_S12_COSMIC_H)
#define __OS_PORT_S12_COSMIC_H

#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */

/*
**  Port-Macros.
*/
#define OsPort_SaveContext()            \
    _BEGIN_BLOCK                     \
    _asm("ldy       _Os_CurrentTCB"); \
    _asm("sts       0,y");           \
    _END_BLOCK

#define OsPort_RestoreContext()         \
    _BEGIN_BLOCK                     \
    _asm("xref      _Os_CurrentTCB"); \
    _asm("ldy       _Os_CurrentTCB"); \
    _asm("lds       0,y");           \
    _END_BLOCK

#define OsPort_StartCurrentTask()      \
    _BEGIN_BLOCK                     \
    _asm("xref      _Os_CurrentTCB"); \
    _asm("ldy       _Os_CurrentTCB"); \
    _asm("lds       0,y");           \
    CPU_RETURN_FROM_INTERRUPT();     \
    _END_BLOCK

#define OsPort_SwitchToISRContext()    _asm("xref _OS_TOS_ISR\nlds   _OS_TOS_ISR")

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __OS_PORT_S12_COSMIC_H  */
