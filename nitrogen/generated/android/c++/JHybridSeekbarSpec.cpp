///
/// JHybridSeekbarSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "JHybridSeekbarSpec.hpp"

// Forward declaration of `Segment` to properly resolve imports.
namespace margelo::nitro::seekbar { struct Segment; }
// Forward declaration of `SeekerColors` to properly resolve imports.
namespace margelo::nitro::seekbar { struct SeekerColors; }
// Forward declaration of `SeekerDimensions` to properly resolve imports.
namespace margelo::nitro::seekbar { struct SeekerDimensions; }

#include <optional>
#include <functional>
#include "JFunc_void_double.hpp"
#include "JFunc_void.hpp"
#include "Segment.hpp"
#include "JFunc_void_Segment.hpp"
#include "JSegment.hpp"
#include <string>
#include <vector>
#include "SeekerColors.hpp"
#include "JSeekerColors.hpp"
#include "SeekerDimensions.hpp"
#include "JSeekerDimensions.hpp"

namespace margelo::nitro::seekbar {

  jni::local_ref<JHybridSeekbarSpec::jhybriddata> JHybridSeekbarSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridSeekbarSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridSeekbarSpec::initHybrid),
    });
  }

  size_t JHybridSeekbarSpec::getExternalMemorySize() noexcept {
    static const auto method = javaClassStatic()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  std::optional<double> JHybridSeekbarSpec::getPosition() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JDouble>()>("getPosition");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->value()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setPosition(std::optional<double> position) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<jni::JDouble> /* position */)>("setPosition");
    method(_javaPart, position.has_value() ? jni::JDouble::valueOf(position.value()) : nullptr);
  }
  std::optional<double> JHybridSeekbarSpec::getDuration() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JDouble>()>("getDuration");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->value()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setDuration(std::optional<double> duration) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<jni::JDouble> /* duration */)>("setDuration");
    method(_javaPart, duration.has_value() ? jni::JDouble::valueOf(duration.value()) : nullptr);
  }
  std::optional<double> JHybridSeekbarSpec::getReadAheadValue() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JDouble>()>("getReadAheadValue");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->value()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setReadAheadValue(std::optional<double> readAheadValue) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<jni::JDouble> /* readAheadValue */)>("setReadAheadValue");
    method(_javaPart, readAheadValue.has_value() ? jni::JDouble::valueOf(readAheadValue.value()) : nullptr);
  }
  std::optional<std::function<void(double /* value */)>> JHybridSeekbarSpec::getOnValueChange() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JFunc_void_double::javaobject>()>("getOnValueChange_cxx");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional([&]() -> std::function<void(double /* value */)> {
      if (__result->isInstanceOf(JFunc_void_double_cxx::javaClassStatic())) [[likely]] {
        auto downcast = jni::static_ref_cast<JFunc_void_double_cxx::javaobject>(__result);
        return downcast->cthis()->getFunction();
      } else {
        return [__result](double value) -> void {
          return __result->invoke(value);
        };
      }
    }()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setOnValueChange(const std::optional<std::function<void(double /* value */)>>& onValueChange) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<JFunc_void_double::javaobject> /* onValueChange */)>("setOnValueChange_cxx");
    method(_javaPart, onValueChange.has_value() ? JFunc_void_double_cxx::fromCpp(onValueChange.value()) : nullptr);
  }
  std::optional<std::function<void()>> JHybridSeekbarSpec::getOnValueChangeFinished() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JFunc_void::javaobject>()>("getOnValueChangeFinished_cxx");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional([&]() -> std::function<void()> {
      if (__result->isInstanceOf(JFunc_void_cxx::javaClassStatic())) [[likely]] {
        auto downcast = jni::static_ref_cast<JFunc_void_cxx::javaobject>(__result);
        return downcast->cthis()->getFunction();
      } else {
        return [__result]() -> void {
          return __result->invoke();
        };
      }
    }()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setOnValueChangeFinished(const std::optional<std::function<void()>>& onValueChangeFinished) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<JFunc_void::javaobject> /* onValueChangeFinished */)>("setOnValueChangeFinished_cxx");
    method(_javaPart, onValueChangeFinished.has_value() ? JFunc_void_cxx::fromCpp(onValueChangeFinished.value()) : nullptr);
  }
  std::optional<std::function<void(const Segment& /* segment */)>> JHybridSeekbarSpec::getOnSegmentChange() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JFunc_void_Segment::javaobject>()>("getOnSegmentChange_cxx");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional([&]() -> std::function<void(const Segment& /* segment */)> {
      if (__result->isInstanceOf(JFunc_void_Segment_cxx::javaClassStatic())) [[likely]] {
        auto downcast = jni::static_ref_cast<JFunc_void_Segment_cxx::javaobject>(__result);
        return downcast->cthis()->getFunction();
      } else {
        return [__result](Segment segment) -> void {
          return __result->invoke(segment);
        };
      }
    }()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setOnSegmentChange(const std::optional<std::function<void(const Segment& /* segment */)>>& onSegmentChange) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<JFunc_void_Segment::javaobject> /* onSegmentChange */)>("setOnSegmentChange_cxx");
    method(_javaPart, onSegmentChange.has_value() ? JFunc_void_Segment_cxx::fromCpp(onSegmentChange.value()) : nullptr);
  }
  std::optional<std::vector<Segment>> JHybridSeekbarSpec::getSegments() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JArrayClass<JSegment>>()>("getSegments");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional([&]() {
      size_t __size = __result->size();
      std::vector<Segment> __vector;
      __vector.reserve(__size);
      for (size_t __i = 0; __i < __size; __i++) {
        auto __element = __result->getElement(__i);
        __vector.push_back(__element->toCpp());
      }
      return __vector;
    }()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setSegments(const std::optional<std::vector<Segment>>& segments) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<jni::JArrayClass<JSegment>> /* segments */)>("setSegments");
    method(_javaPart, segments.has_value() ? [&]() {
      size_t __size = segments.value().size();
      jni::local_ref<jni::JArrayClass<JSegment>> __array = jni::JArrayClass<JSegment>::newArray(__size);
      for (size_t __i = 0; __i < __size; __i++) {
        const auto& __element = segments.value()[__i];
        __array->setElement(__i, *JSegment::fromCpp(__element));
      }
      return __array;
    }() : nullptr);
  }
  std::optional<SeekerColors> JHybridSeekbarSpec::getSeekerColors() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JSeekerColors>()>("getSeekerColors");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toCpp()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setSeekerColors(const std::optional<SeekerColors>& seekerColors) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<JSeekerColors> /* seekerColors */)>("setSeekerColors");
    method(_javaPart, seekerColors.has_value() ? JSeekerColors::fromCpp(seekerColors.value()) : nullptr);
  }
  std::optional<SeekerDimensions> JHybridSeekbarSpec::getSeekerDimensions() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JSeekerDimensions>()>("getSeekerDimensions");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toCpp()) : std::nullopt;
  }
  void JHybridSeekbarSpec::setSeekerDimensions(const std::optional<SeekerDimensions>& seekerDimensions) {
    static const auto method = javaClassStatic()->getMethod<void(jni::alias_ref<JSeekerDimensions> /* seekerDimensions */)>("setSeekerDimensions");
    method(_javaPart, seekerDimensions.has_value() ? JSeekerDimensions::fromCpp(seekerDimensions.value()) : nullptr);
  }

  // Methods
  

} // namespace margelo::nitro::seekbar
