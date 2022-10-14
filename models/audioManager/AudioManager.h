#pragma once
#include <string>

// Namespace to store functions that manage the musics.
namespace AudioManager
{
    /**
     * \brief Plays the audio file at the given path (must be a .wav file)
     * \param path The path to the audio file
     * \param repeat Whether or not the audio should repeat
     */
    void Play(const std::string& path, const bool repeat);
    void Stop();
}