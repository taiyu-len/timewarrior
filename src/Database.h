////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2015 - 2016, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDED_DATABASE
#define INCLUDED_DATABASE

#include <Datafile.h>
#include <Interval.h>
#include <Daterange.h>
#include <vector>
#include <string>

class Database
{
public:
  Database () = default;
  void initialize (const std::string&);
  void commit ();
  std::vector <std::string> files () const;

  std::string lastLine ();
  std::vector <std::string> allLines ();

  void clearExclusions ();
  void addExclusion (const std::string&);
  void addInterval (const Interval&);
  void deleteInterval (const Interval&);
  void modifyInterval (const Interval&, const Interval&);

  std::string dump () const;

private:
  unsigned int getDatafile (int, int);
  std::vector <Daterange> segmentRange (const Daterange&);
  void initializeDatafiles ();
  void validateAddition (const Interval&) const;

private:
  std::string               _location   {"~/.timewarrior/data"};
  std::vector <Datafile>    _files      {};
  std::vector <std::string> _exclusions {};
};

#endif
