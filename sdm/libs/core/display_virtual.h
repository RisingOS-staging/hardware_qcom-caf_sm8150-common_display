/*
* Copyright (c) 2014 - 2016, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright notice, this list of
*      conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright notice, this list of
*      conditions and the following disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its contributors may be used to
*      endorse or promote products derived from this software without specific prior written
*      permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __DISPLAY_VIRTUAL_H__
#define __DISPLAY_VIRTUAL_H__

#include <private/hw_info_types.h>
#include "display_base.h"
#include "dump_impl.h"

namespace sdm {

class HWVirtualInterface;

class DisplayVirtual : public DisplayBase, DumpImpl {
 public:
  DisplayVirtual(DisplayEventHandler *event_handler, HWInfoInterface *hw_info_intf,
                 BufferSyncHandler *buffer_sync_handler, CompManager *comp_manager,
                 RotatorInterface *rotator_intf);
  virtual DisplayError Init();
  virtual DisplayError Deinit();
  virtual DisplayError Flush();
  virtual DisplayError GetDisplayState(DisplayState *state);
  virtual DisplayError GetNumVariableInfoConfigs(uint32_t *count);
  virtual DisplayError GetConfig(uint32_t index, DisplayConfigVariableInfo *variable_info);
  virtual DisplayError GetActiveConfig(uint32_t *index);
  virtual DisplayError GetVSyncState(bool *enabled);
  virtual DisplayError SetDisplayState(DisplayState state);
  virtual DisplayError SetVSyncState(bool enable);
  virtual void SetIdleTimeoutMs(uint32_t timeout_ms);
  virtual DisplayError SetMaxMixerStages(uint32_t max_mixer_stages);
  virtual DisplayError SetDisplayMode(uint32_t mode);
  virtual DisplayError GetRefreshRateRange(uint32_t *min_refresh_rate, uint32_t *max_refresh_rate);
  virtual DisplayError SetRefreshRate(uint32_t refresh_rate);
  virtual bool IsUnderscanSupported();
  virtual DisplayError SetPanelBrightness(int level);
  virtual void AppendDump(char *buffer, uint32_t length);
  virtual DisplayError SetCursorPosition(int x, int y);

 private:
  virtual DisplayError SetActiveConfigLocked(uint32_t index) {
    return kErrorNotSupported;
  }
  virtual DisplayError SetActiveConfigLocked(DisplayConfigVariableInfo *variable_info);
};

}  // namespace sdm

#endif  // __DISPLAY_VIRTUAL_H__

