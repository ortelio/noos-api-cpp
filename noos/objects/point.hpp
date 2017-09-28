#ifndef NOOS_OBJECT_POINT
#define NOOS_OBJECT_POINT
#include "includes.ihh"
/*
 * LICENSE HERE
 */
namespace noos {
namespace object {
/**
 * @struct point
 * @brief encapsulate point position vector
 * @version 0.7.0
 * @date 19 August 2016
 * @author Alex Giokas <a.gkiokas@ortelio.co.uk>
 */
template <class value_type>
struct point
{
    /// coordinates
	value_type x = 0;
    value_type y = 0;
    value_type z = 0;

    /// @brief default constructor
    point() = default;

    /// @brief constructor taking parameters x, y and z
    point(value_type x_data,
          value_type y_data,
          value_type z_data);

    /// @brief Construct using library "json for modern c++"
    point(const json::const_iterator & position);
   
    /// @return a JSON object
    json::object_t to_json() const;
   
    /// @brief Equality operator
    bool operator==(const noos::object::point<value_type> & rhs) const;
};

/**
 * @struct point2d
 * @brief encapsulate point of 2 dimensions (x, y)
 * @version 0.8.0
 * @date 28.09.2017
 */
template <class value_type>
struct point2d
{
    /// coordinates
	value_type x = 0;
    value_type y = 0;

    /// @brief default constructor
    point2d() = default;

    /// @brief constructor taking parameters x, y and z
    point2d(value_type x_data,
          value_type y_data);

    /// @brief Construct using library "json for modern c++"
    point2d(const json::const_iterator & position);
   
    /// @return a JSON object
    json::object_t to_json() const;
   
    /// @brief Equality operator
    bool operator==(const noos::object::point<value_type> & rhs) const;
};
#include "point.tpl"
}
}
#endif
