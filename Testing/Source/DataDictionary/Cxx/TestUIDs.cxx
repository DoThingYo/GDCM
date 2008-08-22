/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmUIDs.h"

#include <iostream>

int TestUIDs(int, char *[])
{
  // {"1.2.840.10008.5.1.4.1.1.2.1","Enhanced CT Image Storage"},
  // uid_1_2_840_10008_5_1_4_1_1_2_1 = 117, // Enhanced CT Image Storage
  const char* s = gdcm::UIDs::GetUIDString( gdcm::UIDs::uid_1_2_840_10008_5_1_4_1_1_2_1 );
  std::cout << s << std::endl;
  const char* n = gdcm::UIDs::GetUIDName( gdcm::UIDs::uid_1_2_840_10008_5_1_4_1_1_2_1 );
  std::cout << n << std::endl;
  const char* s1 = gdcm::UIDs::GetUIDString( gdcm::UIDs::EnhancedCTImageStorage );
  std::cout << s1 << std::endl;
  const char* n1 = gdcm::UIDs::GetUIDName( gdcm::UIDs::EnhancedCTImageStorage );
  std::cout << n1 << std::endl;

  gdcm::UIDs uid;
  uid.SetFromUID( "1.2.840.10008.5.1.4.1.1.2.1" );
  std::cout << "This is : " << uid.GetName() << std::endl;

  return 0;
}
