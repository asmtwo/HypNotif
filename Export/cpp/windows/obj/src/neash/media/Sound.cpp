#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_events_ErrorEvent
#include <neash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IOErrorEvent
#include <neash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_SampleDataEvent
#include <neash/events/SampleDataEvent.h>
#endif
#ifndef INCLUDED_neash_events_TextEvent
#include <neash/events/TextEvent.h>
#endif
#ifndef INCLUDED_neash_media_ID3Info
#include <neash/media/ID3Info.h>
#endif
#ifndef INCLUDED_neash_media_Sound
#include <neash/media/Sound.h>
#endif
#ifndef INCLUDED_neash_media_SoundChannel
#include <neash/media/SoundChannel.h>
#endif
#ifndef INCLUDED_neash_media_SoundLoaderContext
#include <neash/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_neash_media_SoundTransform
#include <neash/media/SoundTransform.h>
#endif
#ifndef INCLUDED_neash_net_URLRequest
#include <neash/net/URLRequest.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace media{

Void Sound_obj::__construct(::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic)
{
bool forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",29)
	super::__construct(null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",30)
	this->bytesLoaded = this->bytesTotal = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",31)
	this->nmeLoading = false;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",32)
	this->nmeDynamicSound = false;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",33)
	if (((stream != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",34)
		this->load(stream,context,forcePlayAsMusic);
	}
}
;
	return null();
}

Sound_obj::~Sound_obj() { }

Dynamic Sound_obj::__CreateEmpty() { return  new Sound_obj; }
hx::ObjectPtr< Sound_obj > Sound_obj::__new(::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(stream,context,__o_forcePlayAsMusic);
	return result;}

Dynamic Sound_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Sound_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture,hx::Null< int >  __o_priority,hx::Null< bool >  __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_SOURCE_PUSH("Sound_obj::addEventListener");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",39)
		this->super::addEventListener(type,listener,useCapture,priority,useWeakReference);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",40)
		if (((type == ::neash::events::SampleDataEvent_obj::SAMPLE_DATA))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",42)
			if (((this->nmeHandle != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",43)
				hx::Throw (HX_CSTRING("Can't use dynamic sound once file loaded"));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",44)
			this->nmeDynamicSound = true;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",45)
			this->nmeLoading = false;
		}
	}
return null();
}


Void Sound_obj::close( ){
{
		HX_SOURCE_PUSH("Sound_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",53)
		if (((this->nmeHandle != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",54)
			::neash::media::Sound_obj::nme_sound_close(this->nmeHandle);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",55)
		this->nmeHandle = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",56)
		this->nmeLoading = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,close,(void))

Void Sound_obj::load( ::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic){
bool forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
	HX_SOURCE_PUSH("Sound_obj::load");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",62)
		this->bytesLoaded = this->bytesTotal = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",63)
		this->nmeHandle = ::neash::media::Sound_obj::nme_sound_from_file(stream->url,forcePlayAsMusic);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",64)
		if (((this->nmeHandle == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",65)
			hx::Throw ((HX_CSTRING("Could not load:") + stream->url));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",70)
			this->url = stream->url;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",71)
			this->nmeLoading = true;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",72)
			this->nmeLoading = false;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",73)
			this->nmeCheckLoading();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Sound_obj,load,(void))

Void Sound_obj::nmeCheckLoading( ){
{
		HX_SOURCE_PUSH("Sound_obj::nmeCheckLoading")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",79)
		if (((bool((bool(!(this->nmeDynamicSound)) && bool(this->nmeLoading))) && bool((this->nmeHandle != null()))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",82)
			Dynamic status = ::neash::media::Sound_obj::nme_sound_get_status(this->nmeHandle);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",83)
			if (((status == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",84)
				hx::Throw (HX_CSTRING("Could not get sound status"));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",85)
			this->bytesLoaded = status->__Field(HX_CSTRING("bytesLoaded"),true);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",86)
			this->bytesTotal = status->__Field(HX_CSTRING("bytesTotal"),true);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",87)
			this->nmeLoading = (this->bytesLoaded < this->bytesTotal);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",88)
			if (((status->__Field(HX_CSTRING("error"),true) != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",89)
				hx::Throw (status->__Field(HX_CSTRING("error"),true));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,nmeCheckLoading,(void))

Void Sound_obj::nmeOnError( ::String msg){
{
		HX_SOURCE_PUSH("Sound_obj::nmeOnError")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",98)
		this->dispatchEvent(::neash::events::IOErrorEvent_obj::__new(::neash::events::IOErrorEvent_obj::IO_ERROR,true,false,msg,null()));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",99)
		this->nmeHandle = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",100)
		this->nmeLoading = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,nmeOnError,(void))

::neash::media::SoundChannel Sound_obj::play( hx::Null< double >  __o_startTime,hx::Null< int >  __o_loops,::neash::media::SoundTransform sndTransform){
double startTime = __o_startTime.Default(0);
int loops = __o_loops.Default(0);
	HX_SOURCE_PUSH("Sound_obj::play");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",106)
		this->nmeCheckLoading();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",107)
		if ((this->nmeDynamicSound)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",109)
			::neash::events::SampleDataEvent request = ::neash::events::SampleDataEvent_obj::__new(::neash::events::SampleDataEvent_obj::SAMPLE_DATA,null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",110)
			this->dispatchEvent(request);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",111)
			if (((request->data->length > (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",112)
				this->nmeHandle = ::neash::media::Sound_obj::nme_sound_channel_create_dynamic(request->data,sndTransform);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",115)
			if (((this->nmeHandle == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",116)
				return null();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",117)
			::neash::media::SoundChannel result = ::neash::media::SoundChannel_obj::createDynamic(this->nmeHandle,sndTransform,hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",118)
			this->nmeHandle = null();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",119)
			return result;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",123)
			if (((bool((this->nmeHandle == null())) || bool(this->nmeLoading)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",124)
				return null();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",126)
			return ::neash::media::SoundChannel_obj::__new(this->nmeHandle,startTime,loops,sndTransform);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",107)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Sound_obj,play,return )

::neash::media::ID3Info Sound_obj::nmeGetID3( ){
	HX_SOURCE_PUSH("Sound_obj::nmeGetID3")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",138)
	this->nmeCheckLoading();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",139)
	if (((bool((this->nmeHandle == null())) || bool(this->nmeLoading)))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",140)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",141)
	::neash::media::ID3Info id3 = ::neash::media::ID3Info_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",142)
	::neash::media::Sound_obj::nme_sound_get_id3(this->nmeHandle,id3);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",143)
	return id3;
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,nmeGetID3,return )

bool Sound_obj::nmeGetIsBuffering( ){
	HX_SOURCE_PUSH("Sound_obj::nmeGetIsBuffering")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",149)
	this->nmeCheckLoading();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",150)
	return (bool(this->nmeLoading) && bool((this->nmeHandle == null())));
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,nmeGetIsBuffering,return )

double Sound_obj::nmeGetLength( ){
	HX_SOURCE_PUSH("Sound_obj::nmeGetLength")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",156)
	if (((bool((this->nmeHandle == null())) || bool(this->nmeLoading)))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",157)
		return (int)0;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/media/Sound.hx",158)
	return ::neash::media::Sound_obj::nme_sound_get_length(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,nmeGetLength,return )

Dynamic Sound_obj::nme_sound_from_file;

Dynamic Sound_obj::nme_sound_get_id3;

Dynamic Sound_obj::nme_sound_get_length;

Dynamic Sound_obj::nme_sound_close;

Dynamic Sound_obj::nme_sound_get_status;

Dynamic Sound_obj::nme_sound_channel_create_dynamic;


Sound_obj::Sound_obj()
{
}

void Sound_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sound);
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(id3,"id3");
	HX_MARK_MEMBER_NAME(isBuffering,"isBuffering");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(nmeLoading,"nmeLoading");
	HX_MARK_MEMBER_NAME(nmeDynamicSound,"nmeDynamicSound");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Sound_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"id3") ) { return inCallProp ? nmeGetID3() : id3; }
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? nmeGetLength() : length; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"nmeGetID3") ) { return nmeGetID3_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		if (HX_FIELD_EQ(inName,"nmeLoading") ) { return nmeLoading; }
		if (HX_FIELD_EQ(inName,"nmeOnError") ) { return nmeOnError_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
		if (HX_FIELD_EQ(inName,"isBuffering") ) { return inCallProp ? nmeGetIsBuffering() : isBuffering; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeGetLength") ) { return nmeGetLength_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_sound_close") ) { return nme_sound_close; }
		if (HX_FIELD_EQ(inName,"nmeDynamicSound") ) { return nmeDynamicSound; }
		if (HX_FIELD_EQ(inName,"nmeCheckLoading") ) { return nmeCheckLoading_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_sound_get_id3") ) { return nme_sound_get_id3; }
		if (HX_FIELD_EQ(inName,"nmeGetIsBuffering") ) { return nmeGetIsBuffering_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_sound_from_file") ) { return nme_sound_from_file; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_sound_get_length") ) { return nme_sound_get_length; }
		if (HX_FIELD_EQ(inName,"nme_sound_get_status") ) { return nme_sound_get_status; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create_dynamic") ) { return nme_sound_channel_create_dynamic; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sound_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"id3") ) { id3=inValue.Cast< ::neash::media::ID3Info >(); return inValue; }
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLoading") ) { nmeLoading=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isBuffering") ) { isBuffering=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_sound_close") ) { nme_sound_close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDynamicSound") ) { nmeDynamicSound=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_sound_get_id3") ) { nme_sound_get_id3=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_sound_from_file") ) { nme_sound_from_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_sound_get_length") ) { nme_sound_get_length=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_sound_get_status") ) { nme_sound_get_status=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nme_sound_channel_create_dynamic") ) { nme_sound_channel_create_dynamic=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sound_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("id3"));
	outFields->push(HX_CSTRING("isBuffering"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("nmeLoading"));
	outFields->push(HX_CSTRING("nmeDynamicSound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_sound_from_file"),
	HX_CSTRING("nme_sound_get_id3"),
	HX_CSTRING("nme_sound_get_length"),
	HX_CSTRING("nme_sound_close"),
	HX_CSTRING("nme_sound_get_status"),
	HX_CSTRING("nme_sound_channel_create_dynamic"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("id3"),
	HX_CSTRING("isBuffering"),
	HX_CSTRING("length"),
	HX_CSTRING("url"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("nmeLoading"),
	HX_CSTRING("nmeDynamicSound"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("close"),
	HX_CSTRING("load"),
	HX_CSTRING("nmeCheckLoading"),
	HX_CSTRING("nmeOnError"),
	HX_CSTRING("play"),
	HX_CSTRING("nmeGetID3"),
	HX_CSTRING("nmeGetIsBuffering"),
	HX_CSTRING("nmeGetLength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_from_file,"nme_sound_from_file");
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_get_id3,"nme_sound_get_id3");
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_get_length,"nme_sound_get_length");
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_close,"nme_sound_close");
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_get_status,"nme_sound_get_status");
	HX_MARK_MEMBER_NAME(Sound_obj::nme_sound_channel_create_dynamic,"nme_sound_channel_create_dynamic");
};

Class Sound_obj::__mClass;

void Sound_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.media.Sound"), hx::TCanCast< Sound_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sound_obj::__boot()
{
	hx::Static(nme_sound_from_file) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_from_file"),(int)2);
	hx::Static(nme_sound_get_id3) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_get_id3"),(int)2);
	hx::Static(nme_sound_get_length) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_get_length"),(int)1);
	hx::Static(nme_sound_close) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_close"),(int)1);
	hx::Static(nme_sound_get_status) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_get_status"),(int)1);
	hx::Static(nme_sound_channel_create_dynamic) = ::neash::Loader_obj::load(HX_CSTRING("nme_sound_channel_create_dynamic"),(int)2);
}

} // end namespace neash
} // end namespace media
