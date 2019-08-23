#pragma once

#ifndef MYPROJECT_FEATURE_HPP
#define MYPROJECT_FEATURE_HPP

#include <string>

namespace myproject
{
class Feature
{
public:
  explicit Feature();

  virtual ~Feature();

  /*!
   * <p>Returns "Feature".</p>
   */
  std::string toString() const;

  /*!
   * <p>Returns "work".</p>
   */
  std::string work() const;
};
}

#endif //MYPROJECT_FEATURE_HPP
