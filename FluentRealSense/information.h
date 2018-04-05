#pragma once
#include "hpp/rs_context.hpp"

using namespace std;
using namespace rs2;

class information
{
public:
  explicit information(const information&) = delete;
  explicit information(information&&) = delete;

  explicit information(const device device) : device_(device) {}
  ~information()
  {
  }

  const char* name() const
  {
    return get_info(RS2_CAMERA_INFO_NAME);
  }

  const char* serial_number() const
  {
    return get_info(RS2_CAMERA_INFO_SERIAL_NUMBER);
  }

  const char* port() const
  {
    return get_info(RS2_CAMERA_INFO_PHYSICAL_PORT);
  }

  const char* firmware_version() const
  {
    return get_info(RS2_CAMERA_INFO_FIRMWARE_VERSION);
  }

  const char* debug_opCode() const
  {
    return get_info(RS2_CAMERA_INFO_DEBUG_OP_CODE);
  }

  const char* advanced_mode() const
  {
    return get_info(RS2_CAMERA_INFO_ADVANCED_MODE);
  }

  const char* product_id() const
  {
    return get_info(RS2_CAMERA_INFO_PRODUCT_ID);
  }

  const char* camera_locked() const
  {
    return get_info(RS2_CAMERA_INFO_CAMERA_LOCKED);
  }

  string dump_diagnostic() const
  {
    string text = "\nDevice Name: ";
    text += name();
    text += "\n  Serial number: ";
    text += serial_number();
    text += "\n  Port: ";
    text += port();
    text += "\n  Firmware version: ";
    text += firmware_version();
    text += "\n  Debug op code: ";
    text += debug_opCode();
    text += "\n  Advanced Mode: ";
    text += advanced_mode();
    text += "\n  Product id: ";
    text += product_id();
    text += "\n  Camera locked: ";
    text += camera_locked();

    return text;
  }

private:

  const char* get_info(const rs2_camera_info info) const
  {
    if (!device_.supports(info))
    {
      return "Not supported";
    }
    return device_.get_info(info);
  }
  device device_;
};

