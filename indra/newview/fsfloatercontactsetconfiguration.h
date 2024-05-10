/*
 * @file fsfloatercontactsetconfiguration.h
 * @brief Contact set configuration floater definitions
 *
 * (C) 2013 Cinder Roxley @ Second Life <cinder.roxley@phoenixviewer.com>
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef FS_FLOATERCONTACTSETCONFIGURATION_H
#define FS_FLOATERCONTACTSETCONFIGURATION_H

#include "llfloater.h"

class LLColorSwatchCtrl;
class LLCheckBoxCtrl;
class LLLineEditor;
class LLButton;

class FSFloaterContactSetConfiguration : public LLFloater
{
public:
	FSFloaterContactSetConfiguration(const LLSD& target_set);
	bool postBuild();
	void onOpen(const LLSD& target_set);
	void draw();
	void setFrustumOrigin(LLView* frustumOrigin);

private:
	~FSFloaterContactSetConfiguration(){};
	void onCommitSetColor();
	void onCommitSetNotifications();
	void onCommitDefaultColor();
	void onRenameSet();
	
	void updateTitle();

	// Wish there was something better to use for this...
	std::string mContactSet;

	LLCheckBoxCtrl*		mNotificationCheckBox;
	LLColorSwatchCtrl*	mSetSwatch;
	LLColorSwatchCtrl*	mGlobalSwatch;
	LLLineEditor*		mSetName;
	LLButton*			mRenameButton;

	LLHandle<LLView>	mFrustumOrigin;
	F32					mContextConeOpacity;
	F32					mContextConeInAlpha;
	F32					mContextConeOutAlpha;
	F32					mContextConeFadeTime;
};

#endif //FS_FLOATERCONTACTSETCONFIGURATION_H
