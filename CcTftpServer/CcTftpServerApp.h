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
 * @page      CcTftpServerApp
 * @copyright Andreas Dirmeier (C) 2017
 * @author    Andreas Dirmeier
 * @par       Web: http://coolcow.de
 * @version   0.01
 * @date      2016-04
 * @par       Language   C++ ANSI V3
 * @brief     Class CcTftpServerApp
 **/
#ifndef CcTftpServerApp_H_
#define CcTftpServerApp_H_

#include "CcBase.h"
#include "CcUserList.h"
#include "CcApp.h"
#include "CcArguments.h"

class CcTftpServerAppPrivate;

/**
 * @brief Class impelmentation
 */
class CcTftpServerApp : public CcApp
{
public:
  /**
   * @brief Constructor
   */
  CcTftpServerApp(void);

  /**
   * @brief Constructor with Arguments
   */
  CcTftpServerApp(const CcArguments& oArguments);

  /**
   * @brief Destructor
   */
  virtual ~CcTftpServerApp( void );

private:
  virtual void run() override;
  void init();

private:
  CcTftpServerAppPrivate* m_pPrivate = nullptr;
  CcArguments m_oArguments;
};

#endif /* CcTftpServerApp_H_ */
