#include"Track.hpp"

#include"Debug.hpp"

namespace NDespair::NAudio
{
    CTrack::CTrack(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        GDebug->ASimpleDirectMediaLayerHandleError(FHandle = Mix_LoadMUS(PPath.c_str()));
    }
    bool CTrack::AIs(const std::string& PPath)
    {
        return(FPath == PPath);
    }
    CTrack* CTrack::APlay()
    {
        GDebug->ASimpleDirectMediaLayerCodeError(Mix_PlayMusic(FHandle , 0));
        return(this);
    }
    CTrack* CTrack::APause()
    {
        Mix_PauseMusic();
        return(this);
    }
    CTrack* CTrack::AResume()
    {
        Mix_ResumeMusic();
        return(this);
    }
    CTrack* CTrack::AStop()
    {
        Mix_HaltMusic();
        return(this);
    }
    CTrack* CTrack::AAccessVolume(std::uint8_t PValue)
    {
        Mix_VolumeMusic(PValue);
        GDebug->AError(Mix_VolumeMusic(SDL_QUERY) != PValue);
        return(this);
    }
    CTrack::~CTrack()
    {
        Mix_FreeMusic(FHandle);
    }
}