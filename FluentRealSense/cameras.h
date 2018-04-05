#pragma once
#include <vector>
#include <memory>
#include "camera.h"
#include "hpp/rs_context.hpp"

using namespace std;
using namespace rs2;

class cameras
{
  using cameras_t = vector<shared_ptr<camera>>;
  using iterator = cameras_t::iterator;
  using const_iterator = cameras_t::const_iterator;

public:
  explicit cameras(const cameras&) = delete; // Remove copy constructor
  explicit cameras(cameras&&) = delete; // Remove move constructor

  cameras() : cameras_(make_shared<cameras_t>())
  {
    context context;
    auto devices = context.query_devices();
    
    if (devices.size() == 0)
    {
      device_hub hub(context);
      auto device = hub.wait_for_device();
    }
    for (const auto dev : devices)
    {
      const auto cam = make_shared<camera>(dev);
      cameras_->push_back(cam);
    }
  }

  ~cameras()
  {
  }

  int capacity() const
  {
    return cameras_->capacity();
  }

  iterator begin() { return cameras_->begin(); }
  iterator end() { return cameras_->end(); }

  const_iterator begin() const { return cameras_->begin(); }
  const_iterator end() const { return cameras_->end(); }
  const_iterator cbegin() const { return cameras_->cbegin(); }
  const_iterator cend() const { return cameras_->cend(); }

  camera get_at(const int pos) const
  {
    const auto cap = capacity();
    if (pos < 0 || pos >= cap)
    {
      throw out_of_range("The range must be greater than or equal to 0 and less than " + to_string(cap));
    }
    return *cameras_->at(pos);
  }

private:
  //! The list of all available cameras, as identified by realsense.
  shared_ptr<cameras_t> cameras_;
};