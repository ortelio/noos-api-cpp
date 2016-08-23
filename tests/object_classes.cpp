/**
 * Copyright 2015 RAPP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * #http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define BOOST_TEST_MODULE ObjectTest
#include <fstream>
#include <chrono>
#include <iostream>
#include <boost/test/unit_test.hpp>

//#include "../includes/objects/face/face.hpp"
//#include "../includes/objects/qr_code/qr_code.hpp"
//#include "../includes/objects/picture/picture.hpp"
//#include "../includes/objects/audio/audio.hpp"
#include "../includes/objects/time/time.hpp"
#include "../includes/objects/point/point.hpp"
#include "../includes/objects/quaternion/quaternion.hpp"



BOOST_AUTO_TEST_SUITE(object_classes_test)

/*
BOOST_AUTO_TEST_CASE(constructors_test)
{
    BOOST_TEST_MESSAGE("constructors test");
    // Test all face constructors work
    // Empty face object
    auto f_ptr = std::make_shared<rapp::object::face>();
    BOOST_CHECK(f_ptr != nullptr);

    // Contruct with coordinates
    rapp::object::face f_valid( 0.5f,0.3f,0.6f,0.8f);

    // Copy Constructor
    rapp::object::face f_copy(f_valid);
    BOOST_CHECK(f_copy == f_valid);

    // Assignment constructor
    rapp::object::face f_asmt = f_copy;
    BOOST_CHECK(f_asmt == f_copy);
    
    // Test all qrCode contructors work
    auto qr_ptr = std::make_shared<rapp::object::qr_code>();
    BOOST_CHECK(qr_ptr != nullptr);

    // Construct with coordinate and message
    rapp::object::qr_code qr_valid (0.1f, 0.1f, "alex");

    // Copy constructor
    rapp::object::qr_code qr_copy(qr_valid);
    BOOST_CHECK(qr_copy == qr_valid);

    // Asignment constructor
    rapp::object::qr_code qr_asmt = qr_copy;
    BOOST_CHECK(qr_copy == qr_asmt);

    // Test all picture contructors work
    // NOTE: Use lena.jpg as the file

    // Construct from a file-path
    rapp::object::picture lena("Lenna.png");

    // Open a byte steam from file, and construct the picture
    std::ifstream bytestream("Lenna.png", std::ios::in | std::ios::binary | std::ios::ate);
    rapp::object::picture b_copy(bytestream);
    BOOST_CHECK(lena == b_copy);

    // Copy constructor
    rapp::object::picture r_copy = lena;
    BOOST_CHECK(lena == r_copy);

    // Assignment
    rapp::object::picture asmt = lena;
    BOOST_CHECK(lena == asmt);

    // audio tests
    rapp::object::audio t1("terminator_1.wav");
    std::ifstream bytes("terminator_1.wav", std::ios::in | std::ios::binary | std::ios::ate);
    rapp::object::audio t1_ifstrm(bytes);

    BOOST_CHECK(t1 == t1_ifstrm);

    rapp::object::audio t2("terminator_2.wav");
    rapp::object::audio t2_cpy = t2;

    //BOOST_CHECK_PREDICATE( std::not_equal_to<rapp::object::audio>(), (t1)(t2) );
    BOOST_CHECK( t2 == t2_cpy );

    rapp::object::ogg og1("recording_sentence1.ogg");
    rapp::object::ogg og2(og1);
    //rapp::object::WAVfileSingleChannel wv1 ("yes-no.wav");

    BOOST_CHECK(og1 == og2);
    //BOOST_CHECK( og1 != wv1 );
}
*/

/**
 *\brief TEST for time object
 *\We check the constructors creating identical objects and comparing 
 *\between them.
 *\Methods seconds and nanoseconds are checked comparing the atributes
 *\between the objects created before. They have to be the same.
 */
BOOST_AUTO_TEST_CASE(object_time_test)
{
    std::chrono::nanoseconds t(1464949299093018853);
    rapp::object::time obj_time1 = rapp::object::time(t);
    rapp::object::time obj_time2 = rapp::object::time(t);
    BOOST_CHECK(obj_time1 ==  obj_time2);

    BOOST_CHECK_EQUAL(obj_time1.seconds(), 1464949299);
    BOOST_CHECK_EQUAL(obj_time1.nanoseconds(), 93018853);

    // assignment constructor
    rapp::object::time obj_time3 = rapp::object::time(obj_time1);
    BOOST_CHECK(obj_time1 == obj_time3); 

    // copy constructor
    auto obj_time4 = obj_time3;
    BOOST_CHECK(obj_time3 == obj_time4);

    // test seconds
    uint32_t s_obj_time1 = obj_time1.seconds();
    uint32_t s_obj_time2 = obj_time2.seconds();
    BOOST_CHECK_EQUAL(s_obj_time1, s_obj_time2);

    // test nanoseconds
    uint64_t n_obj_time1 = obj_time1.nanoseconds();
    uint64_t n_obj_time2 = obj_time2.nanoseconds();
    BOOST_CHECK_EQUAL(n_obj_time1, n_obj_time2);

    // test comparison operator
    BOOST_CHECK(obj_time1 == obj_time2);
}

/**
 *\brief TEST for point object
 *\The constructors are checked creating identical
 *\objects and comparing between them.
 */
BOOST_AUTO_TEST_CASE(object_point_test)
{
    double x = 0.9999999776482582;
    double y = 0.9999999776482582;
    double z = 0.0;
    auto point1 = rapp::object::point(x, y, z);
    auto point2 = rapp::object::point(x, y, z);
    BOOST_CHECK(point1 ==  point2);

    auto point3 = rapp::object::point(point1);
    BOOST_CHECK(point1 == point3);

    auto point4 = rapp::object::point(0, 0, 0);
    auto point0 = rapp::object::point();
    BOOST_CHECK(point4 == point0);
    
    auto point5 = point4;
    BOOST_CHECK(point4 == point5);

    //to check that the variable is the same
    BOOST_CHECK_EQUAL(point1.x, 0.9999999776482582);
    BOOST_CHECK_EQUAL(point1.y, 0.9999999776482582);

}

/**
 *\brief TEST for quaternion object 
 *\The constructor are checked creating identical objects
 *\and comparing between them.
 *\A extra checked was added to guarantee the atributes
 *\have the same valor that constants created.
 */
BOOST_AUTO_TEST_CASE(object_quaternion_test)
{
    auto quat0 = rapp::object::quaternion();
    auto quat1 = rapp::object::quaternion(0, 0, 0, 1);
    BOOST_CHECK( quat0 == quat1);
    
    double x = 0.0;
    double y = 0.0;
    double z = 0.3062984133859556;
    double w = 0.9519355450644997;
    
    auto quat2 = rapp::object::quaternion(x, y, z, w);
    auto quat3 = rapp::object::quaternion(quat2);
    BOOST_CHECK(quat2 == quat3);

    BOOST_CHECK_EQUAL(quat3.z, 0.3062984133859556);
    BOOST_CHECK_EQUAL(quat3.w, 0.9519355450644997);

    auto quat4 = quat3;
    BOOST_CHECK(quat3 == quat4);
}

BOOST_AUTO_TEST_SUITE_END()
