//
// Manta - Structural Variant and Indel Caller
// Copyright (c) 2013-2019 Illumina, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

/// \file
/// \author Chris Saunders
///

#pragma once

#include <iosfwd>

namespace illumina {

/// base-class for all command-line programs
///
/// this is used to standardize bottom-level exception handling
struct Program {
  virtual ~Program() = default;

  int run(int argc, char* argv[]) const;

  virtual const char* name() const = 0;

  const char* version() const;

  const char* compiler() const;

  const char* buildTime() const;

protected:
  virtual void runInternal(int argc, char* argv[]) const = 0;

private:
  void post_catch(int argc, char* argv[], std::ostream& os) const;
};

}  // namespace illumina
