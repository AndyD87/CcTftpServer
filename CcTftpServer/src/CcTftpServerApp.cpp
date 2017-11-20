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
#include "CcConsole.h"

namespace CcTftpServerAppStrings
{
const CcString ArgRootDir("-rootdir");
const CcString ArgPort("-port");
const CcString ArgRead("-read");
const CcString ArgWrite("-write");
}

class CcTftpServerAppPrivate
{
public:
  CcTftpServerConfig oServerconfig;
};

CcTftpServerApp::CcTftpServerApp()
{
  init();
}

CcTftpServerApp::CcTftpServerApp(const CcArguments& oArguments) : m_oArguments(oArguments) 
{
  init();
}

CcTftpServerApp::~CcTftpServerApp()
{
  CCMONITORDELETE(m_pPrivate);
  delete m_pPrivate;
}

void CcTftpServerApp::run()
{
  for (size_t i = 0; i < m_oArguments.size(); i++)
  {
    if (m_oArguments[i].compareInsensitve(CcTftpServerAppStrings::ArgRootDir) &&
        m_oArguments.size() > i+1)
    {
      i++;
      m_pPrivate->oServerconfig.setRootDir(m_oArguments[i]);
      if (!CcDirectory::exists(m_oArguments[i]))
      {
        CcConsole::writeLine("Warning: " + m_oArguments[i] + " as root dir not yet existing");
      }
    }
    else if (m_oArguments[i].compareInsensitve(CcTftpServerAppStrings::ArgPort) &&
            m_oArguments.size() > i + 1)
    {
      i++;
      bool bOk = false;
      uint16 uiPort = m_oArguments[i].toUint16(&bOk);
      if (bOk)
      {
        m_pPrivate->oServerconfig.setPort(uiPort);
        CcConsole::writeLine("Port: " + m_oArguments[i]);
      }
      else
      {
        CcConsole::writeLine("Invalid number for port: " + m_oArguments[i]);
      }
    }
    else if (m_oArguments[i].compareInsensitve(CcTftpServerAppStrings::ArgRead) &&
            m_oArguments.size() > i + 1)
    {
      i++;
      bool bOk = false;
      bool uiPort = m_oArguments[i].toBool(&bOk);
      if (bOk)
      {
        m_pPrivate->oServerconfig.setReadEnabled(uiPort);
        CcConsole::writeLine("Read: " + m_oArguments[i]);
      }
      else
      {
        CcConsole::writeLine("Invalid boolean for read: " + m_oArguments[i]);
      }
    }
    else if (m_oArguments[i].compareInsensitve(CcTftpServerAppStrings::ArgWrite) &&
            m_oArguments.size() > i + 1)
    {
      i++;
      bool bOk = false;
      bool uiPort = m_oArguments[i].toBool(&bOk);
      if (bOk)
      {
        m_pPrivate->oServerconfig.setWriteEnabled(uiPort);
        CcConsole::writeLine("Write: " + m_oArguments[i]);
      }
      else
      {
        CcConsole::writeLine("Invalid boolean for write: " + m_oArguments[i]);
      }
    }
  }
  CcTftpServer oTftpServer(m_pPrivate->oServerconfig);
  oTftpServer.exec();
}

void CcTftpServerApp::init()
{
  m_pPrivate = new CcTftpServerAppPrivate();
  CCMONITORNEW(m_pPrivate);
}