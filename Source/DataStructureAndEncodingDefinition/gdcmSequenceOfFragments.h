/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006 Mathieu Malaterre
  Copyright (c) 1993-2005 CREATIS
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __gdcmSequenceOfFragments_h
#define __gdcmSequenceOfFragments_h

#include "gdcmValue.h"
#include "gdcmVL.h"
#include "gdcmFragment.h"
#include "gdcmBasicOffsetTable.h"

namespace gdcm
{

	// FIXME gdcmSequenceOfItems qnd gdcmSequenceOfFragments 
	// should be rethink (duplicate code)
/**
 * \brief Class to represent a Sequence Of Fragments
 * \todo I do not enforce that Sequence of Fragments ends with a SQ end del
 */
class GDCM_EXPORT SequenceOfFragments : public Value
{
  template <typename TSwap> friend class IOSerialize;
public:
  // Typdefs:
  typedef std::vector<Fragment> FragmentVector;

/// \brief constructor (UndefinedLength by default)
  SequenceOfFragments():Table(),SequenceLengthField(0) { }

  /// \brief Returns the SQ length, as read from disk
  VL GetLength() const { 
	  return SequenceLengthField; }
  /// \brief Sets the actual SQ length
  void SetLength(VL length) {
    SequenceLengthField = length;
  }
  void Clear() {}

//template <typename TSwap>
//  IStream &Read(IStream &is);
//template <typename TSwap>
//  OStream const & Write(OStream &os) const;

  /// \brief Appends a Fragment to the already added ones
  void AddFragment(Fragment const &item);

  // Compute the length of all fragments (and framents only!).
  // Basically the size of the PixelData as stored (in bytes).
  unsigned long ComputeByteLength() const;

  // Compute the length of fragments (in bytes)+ length of tag...
  // to be used for computation of Group Length
  VL ComputeLength() const;

  // Get the buffer
  bool GetBuffer(char *buffer, unsigned long length) const;
  bool GetFragBuffer(unsigned int fragNb, char *buffer, unsigned long &length) const;
  unsigned int GetNumberOfFragments() const;
  const Fragment& GetFragment(unsigned int num) const;

  // Write the buffer of each fragment (call WriteBuffer on all Fragments, which are
  // ByteValue). No Table information is written.
  bool WriteBuffer(std::ostream &os) const;

  const BasicOffsetTable &GetTable() const { return Table; }

protected:
  void Print(std::ostream &os) const {
    os << "SQ L= " << SequenceLengthField << "\n";
    os << "Table:" << Table << "\n";
    FragmentVector::const_iterator it =
      Fragments.begin();
    for(;it != Fragments.end(); ++it)
      {
      os << "  " << *it << "\n";
      }
  }

private:
public:
  VL SequenceLengthField;
  BasicOffsetTable Table;
  /// \brief Vector of Sequence Fragments
  FragmentVector Fragments;
};

} // end namespace gdcm

#endif //__gdcmSequenceOfFragments_h
