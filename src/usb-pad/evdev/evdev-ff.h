#ifndef EVDEV_FF_H
#define EVDEV_FF_H

#include <linux/input.h>
#include "../usb-pad.h"

namespace usb_pad { namespace evdev {

enum EffectID
{
	EFF_CONSTANT = 0,
	EFF_SPRING,
	EFF_DAMPER,
	EFF_FRICTION,
};

class EvdevFF
{
public:
	EvdevFF(int fd);
	~EvdevFF();

	void SetConstantForce(int force);
	void SetSpringForce(const spring& force, int caps);
	void SetDamperForce(const damper& force, int caps);
	void SetFrictionForce(const friction& frict);
	void SetAutoCenter(int value);
	void SetGain(int gain);
	void DisableForce(EffectID force);
	void TokenOut(ff_data *ffdata, bool hires);

private:
	int mHandle;
	ff_effect mEffect;
	ff_effect mEffRumble;
	ff_state mFFstate;
	int mEffIds[3] = {-1, -1, -1}; //save ids just in case

	bool mUseRumble;
	int mLastValue;
};

}} //namespace
#endif
