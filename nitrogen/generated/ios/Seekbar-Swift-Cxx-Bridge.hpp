///
/// Seekbar-Swift-Cxx-Bridge.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `HybridSeekbarSpec` to properly resolve imports.
namespace margelo::nitro::seekbar { class HybridSeekbarSpec; }
// Forward declaration of `SeekerColors` to properly resolve imports.
namespace margelo::nitro::seekbar { struct SeekerColors; }
// Forward declaration of `SeekerDimensions` to properly resolve imports.
namespace margelo::nitro::seekbar { struct SeekerDimensions; }
// Forward declaration of `Segment` to properly resolve imports.
namespace margelo::nitro::seekbar { struct Segment; }

// Forward declarations of Swift defined types
// Forward declaration of `HybridSeekbarSpec_cxx` to properly resolve imports.
namespace Seekbar { class HybridSeekbarSpec_cxx; }

// Include C++ defined types
#include "HybridSeekbarSpec.hpp"
#include "SeekerColors.hpp"
#include "SeekerDimensions.hpp"
#include "Segment.hpp"
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

/**
 * Contains specialized versions of C++ templated types so they can be accessed from Swift,
 * as well as helper functions to interact with those C++ types from Swift.
 */
namespace margelo::nitro::seekbar::bridge::swift {

  // pragma MARK: std::optional<double>
  /**
   * Specialized version of `std::optional<double>`.
   */
  using std__optional_double_ = std::optional<double>;
  inline std::optional<double> create_std__optional_double_(const double& value) {
    return std::optional<double>(value);
  }
  
  // pragma MARK: std::function<void(double /* value */)>
  /**
   * Specialized version of `std::function<void(double)>`.
   */
  using Func_void_double = std::function<void(double /* value */)>;
  /**
   * Wrapper class for a `std::function<void(double / * value * /)>`, this can be used from Swift.
   */
  class Func_void_double_Wrapper final {
  public:
    explicit Func_void_double_Wrapper(std::function<void(double /* value */)>&& func): _function(std::make_shared<std::function<void(double /* value */)>>(std::move(func))) {}
    inline void call(double value) const {
      _function->operator()(value);
    }
  private:
    std::shared_ptr<std::function<void(double /* value */)>> _function;
  };
  Func_void_double create_Func_void_double(void* _Nonnull swiftClosureWrapper);
  inline Func_void_double_Wrapper wrap_Func_void_double(Func_void_double value) {
    return Func_void_double_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::optional<std::function<void(double /* value */)>>
  /**
   * Specialized version of `std::optional<std::function<void(double / * value * /)>>`.
   */
  using std__optional_std__function_void_double____value______ = std::optional<std::function<void(double /* value */)>>;
  inline std::optional<std::function<void(double /* value */)>> create_std__optional_std__function_void_double____value______(const std::function<void(double /* value */)>& value) {
    return std::optional<std::function<void(double /* value */)>>(value);
  }
  
  // pragma MARK: std::function<void()>
  /**
   * Specialized version of `std::function<void()>`.
   */
  using Func_void = std::function<void()>;
  /**
   * Wrapper class for a `std::function<void()>`, this can be used from Swift.
   */
  class Func_void_Wrapper final {
  public:
    explicit Func_void_Wrapper(std::function<void()>&& func): _function(std::make_shared<std::function<void()>>(std::move(func))) {}
    inline void call() const {
      _function->operator()();
    }
  private:
    std::shared_ptr<std::function<void()>> _function;
  };
  Func_void create_Func_void(void* _Nonnull swiftClosureWrapper);
  inline Func_void_Wrapper wrap_Func_void(Func_void value) {
    return Func_void_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::optional<std::function<void()>>
  /**
   * Specialized version of `std::optional<std::function<void()>>`.
   */
  using std__optional_std__function_void____ = std::optional<std::function<void()>>;
  inline std::optional<std::function<void()>> create_std__optional_std__function_void____(const std::function<void()>& value) {
    return std::optional<std::function<void()>>(value);
  }
  
  // pragma MARK: std::optional<std::string>
  /**
   * Specialized version of `std::optional<std::string>`.
   */
  using std__optional_std__string_ = std::optional<std::string>;
  inline std::optional<std::string> create_std__optional_std__string_(const std::string& value) {
    return std::optional<std::string>(value);
  }
  
  // pragma MARK: std::function<void(const Segment& /* segment */)>
  /**
   * Specialized version of `std::function<void(const Segment&)>`.
   */
  using Func_void_Segment = std::function<void(const Segment& /* segment */)>;
  /**
   * Wrapper class for a `std::function<void(const Segment& / * segment * /)>`, this can be used from Swift.
   */
  class Func_void_Segment_Wrapper final {
  public:
    explicit Func_void_Segment_Wrapper(std::function<void(const Segment& /* segment */)>&& func): _function(std::make_shared<std::function<void(const Segment& /* segment */)>>(std::move(func))) {}
    inline void call(Segment segment) const {
      _function->operator()(segment);
    }
  private:
    std::shared_ptr<std::function<void(const Segment& /* segment */)>> _function;
  };
  Func_void_Segment create_Func_void_Segment(void* _Nonnull swiftClosureWrapper);
  inline Func_void_Segment_Wrapper wrap_Func_void_Segment(Func_void_Segment value) {
    return Func_void_Segment_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::optional<std::function<void(const Segment& /* segment */)>>
  /**
   * Specialized version of `std::optional<std::function<void(const Segment& / * segment * /)>>`.
   */
  using std__optional_std__function_void_const_Segment_____segment______ = std::optional<std::function<void(const Segment& /* segment */)>>;
  inline std::optional<std::function<void(const Segment& /* segment */)>> create_std__optional_std__function_void_const_Segment_____segment______(const std::function<void(const Segment& /* segment */)>& value) {
    return std::optional<std::function<void(const Segment& /* segment */)>>(value);
  }
  
  // pragma MARK: std::vector<Segment>
  /**
   * Specialized version of `std::vector<Segment>`.
   */
  using std__vector_Segment_ = std::vector<Segment>;
  inline std::vector<Segment> create_std__vector_Segment_(size_t size) {
    std::vector<Segment> vector;
    vector.reserve(size);
    return vector;
  }
  
  // pragma MARK: std::optional<std::vector<Segment>>
  /**
   * Specialized version of `std::optional<std::vector<Segment>>`.
   */
  using std__optional_std__vector_Segment__ = std::optional<std::vector<Segment>>;
  inline std::optional<std::vector<Segment>> create_std__optional_std__vector_Segment__(const std::vector<Segment>& value) {
    return std::optional<std::vector<Segment>>(value);
  }
  
  // pragma MARK: std::optional<SeekerColors>
  /**
   * Specialized version of `std::optional<SeekerColors>`.
   */
  using std__optional_SeekerColors_ = std::optional<SeekerColors>;
  inline std::optional<SeekerColors> create_std__optional_SeekerColors_(const SeekerColors& value) {
    return std::optional<SeekerColors>(value);
  }
  
  // pragma MARK: std::optional<SeekerDimensions>
  /**
   * Specialized version of `std::optional<SeekerDimensions>`.
   */
  using std__optional_SeekerDimensions_ = std::optional<SeekerDimensions>;
  inline std::optional<SeekerDimensions> create_std__optional_SeekerDimensions_(const SeekerDimensions& value) {
    return std::optional<SeekerDimensions>(value);
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>`.
   */
  using std__shared_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_ = std::shared_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>;
  std::shared_ptr<margelo::nitro::seekbar::HybridSeekbarSpec> create_std__shared_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_(std__shared_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_ cppType);
  
  // pragma MARK: std::weak_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>
  using std__weak_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_ = std::weak_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>;
  inline std__weak_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_ weakify_std__shared_ptr_margelo__nitro__seekbar__HybridSeekbarSpec_(const std::shared_ptr<margelo::nitro::seekbar::HybridSeekbarSpec>& strong) { return strong; }

} // namespace margelo::nitro::seekbar::bridge::swift
