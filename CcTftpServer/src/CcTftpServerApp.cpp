/*
* This file is part of CcTftpServerApp.
*
* CcTftpServerApp is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* CcTftpServerApp is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with CcTftpServerApp.  If not, see <http://www.gnu.org/licenses/>.
**/
/**
* @file
* @copyright Andreas Dirmeier (C) 2017
* @author    Andreas Dirmeier
* @par       Web: http://coolcow.de
* @version   0.01
* @date      2016-04
* @par       Language   C++ ANSI V3
* @brief     Implemtation of class CcTftpServerApp
*/
#include "CcKernel.h"
#include "CcDirectory.h"
#include "CcTftpServerApp.h"
#include "CcFile.h"
#include "CcConsole.h"
#include "CcStatus.h"
#include "CcTftpServer.h"

class CcTftpServerAppPrivate
{
public:
};

CcTftpServerApp::CcTftpServerApp()
{
}

CcTftpServerApp::CcTftpServerApp(const CcArguments& oArguments) : m_oArguments(oArguments) 
{
}

CcTftpServerApp::~CcTftpServerApp()
{
  CCMONITORDELETE(m_pPrivate);
  delete m_pPrivate;
}

void CcTftpServerApp::run()
{
  CcTftpServer oTftpServer;
  oTftpServer.config().setRootDir("C:/tftpboot");
  oTftpServer.exec();
}

void CcTftpServerApp::init()
{
  m_pPrivate = new CcTftpServerAppPrivate();
  CCMONITORNEW(m_pPrivate);
}