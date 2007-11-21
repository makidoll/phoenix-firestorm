/**
 * @file llparcelrequest.cpp
 * @brief Implementation of the LLParcelRequest class.
 *
 * Copyright (c) 2006-$CurrentYear$, Linden Research, Inc.
 * $License$
 */

#include "llviewerprecompiledheaders.h"

#include "llagent.h"
#include "llclassifiedstatsresponder.h"

#include "llpanelclassified.h"
#include "llpanel.h"
#include "llhttpclient.h"
#include "llsdserialize.h"
#include "llviewerregion.h"
#include "llview.h"
#include "message.h"

LLClassifiedStatsResponder::LLClassifiedStatsResponder(LLViewHandle classified_panel_handle, LLUUID classified_id)
: mClassifiedPanelHandle(classified_panel_handle),
mClassifiedID(classified_id)
{
}
/*virtual*/
void LLClassifiedStatsResponder::result(const LLSD& content)
{
	S32 teleport = content["teleport_clicks"].asInteger();
	S32 map = content["map_clicks"].asInteger();
	S32 profile = content["profile_clicks"].asInteger();
	S32 search_teleport = content["search_teleport_clicks"].asInteger();
	S32 search_map = content["search_map_clicks"].asInteger();
	S32 search_profile = content["search_profile_clicks"].asInteger();

	LLPanelClassified* classified_panelp = (LLPanelClassified*)LLPanel::getPanelByHandle(mClassifiedPanelHandle);

	if(classified_panelp)
	{
		classified_panelp->setClickThrough(mClassifiedID, 
											teleport + search_teleport, 
											map + search_map,
											profile + search_profile,
											true);
	}

}

/*virtual*/
void LLClassifiedStatsResponder::error(U32 status, const std::string& reason)
{
	llinfos << "LLClassifiedStatsResponder::error("
		<< status << ": " << reason << ")" << llendl;
}


