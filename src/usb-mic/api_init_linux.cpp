#include "audiodeviceproxy.h"
#include "audiodev-noop.h"
#include "audiodev-pulse.h"

void RegisterAudioDevice::Initialize()
{
	auto& inst = RegisterAudioDevice::instance();
	inst.Add(audiodev_noop::APINAME, new AudioDeviceProxy<audiodev_noop::NoopAudioDevice>());
	inst.Add(audiodev_pulse::APINAME, new AudioDeviceProxy<audiodev_pulse::PulseAudioDevice>());
}