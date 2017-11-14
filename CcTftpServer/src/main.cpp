/*
* This file is part of CcTftpServer.
*
* CcTftpServer is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* CcTftpServer is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with CcTftpServer.  If not, see <http://www.gnu.org/licenses/>.
**/
/**
* @copyright Andreas Dirmeier (C) 2017
* @author    Andreas Dirmeier
* @par       Web: http://coolcow.de
* @version    0.01
* @date       2016-04
* @par        Language   C++ ANSI V3
* @file     main.cpp
* @brief    Development default CLI-Application for testing new Implementations
*/

#include "CcBase.h"
#include "CcKernel.h"
#include "CcTftpServerApp.h"

int main(int argc, char **argv)
{
  CcKernel::initCLI();
  CcTftpServerApp m_TftpServer(CcArguments(argc, argv));
  return m_TftpServer.exec();
}
