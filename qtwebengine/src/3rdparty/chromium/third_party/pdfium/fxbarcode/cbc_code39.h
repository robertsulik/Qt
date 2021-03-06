// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXBARCODE_CBC_CODE39_H_
#define FXBARCODE_CBC_CODE39_H_

#include "core/fxcrt/fx_coordinates.h"
#include "core/fxcrt/fx_string.h"
#include "core/fxcrt/fx_system.h"
#include "core/fxge/fx_dib.h"
#include "fxbarcode/cbc_onecode.h"

class CBC_OnedCode39Writer;

class CBC_Code39 : public CBC_OneCode {
 public:
  CBC_Code39();
  ~CBC_Code39() override;

  // CBC_OneCode:
  bool Encode(const CFX_WideStringC& contents, bool isDevice) override;
  bool RenderDevice(CFX_RenderDevice* device,
                    const CFX_Matrix* matrix) override;
  BC_TYPE GetType() override;

  bool SetTextLocation(BC_TEXT_LOC location);
  bool SetWideNarrowRatio(int8_t ratio);

 private:
  CBC_OnedCode39Writer* GetOnedCode39Writer();

  CFX_WideString m_renderContents;
};

#endif  // FXBARCODE_CBC_CODE39_H_
