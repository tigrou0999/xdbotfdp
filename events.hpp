#pragma once

#include "render_settings.hpp"

#include <Geode/Geode.hpp>

// NOTE: The ffmpeg-api event bridge relied on geode::Event, which was reworked in Geode 5.
// Temporary stub so the mod compiles: video rendering through ffmpeg is unavailable until
// this is ported to the Geode 5 event system.
namespace ffmpeg::events {

class Recorder {
public:
    Recorder() = default;
    ~Recorder() = default;

    bool isValid() const {return false;}

    geode::Result<> init(RenderSettings const&) {
        return geode::Err("ffmpeg rendering is not available in this build.");
    }

    void stop() {}

    geode::Result<> writeFrame(const std::vector<uint8_t>&) {
        return geode::Err("ffmpeg rendering is not available in this build.");
    }

    static std::vector<std::string> getAvailableCodecs() {
        return {};
    }
};

class AudioMixer {
public:
    AudioMixer() = delete;

    static geode::Result<> mixVideoAudio(std::filesystem::path const&, std::filesystem::path const&, std::filesystem::path const&) {
        return geode::Err("ffmpeg rendering is not available in this build.");
    }

    static geode::Result<> mixVideoRaw(std::filesystem::path const&, const std::vector<float>&, std::filesystem::path const&) {
        return geode::Err("ffmpeg rendering is not available in this build.");
    }
};

}
