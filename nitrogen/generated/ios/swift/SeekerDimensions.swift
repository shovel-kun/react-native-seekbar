///
/// SeekerDimensions.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `SeekerDimensions`, backed by a C++ struct.
 */
public typealias SeekerDimensions = margelo.nitro.seekbar.SeekerDimensions

public extension SeekerDimensions {
  private typealias bridge = margelo.nitro.seekbar.bridge.swift

  /**
   * Create a new instance of `SeekerDimensions`.
   */
  init(trackHeight: Double?, progressHeight: Double?, thumbRadius: Double?, gap: Double?) {
    self.init({ () -> bridge.std__optional_double_ in
      if let __unwrappedValue = trackHeight {
        return bridge.create_std__optional_double_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_double_ in
      if let __unwrappedValue = progressHeight {
        return bridge.create_std__optional_double_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_double_ in
      if let __unwrappedValue = thumbRadius {
        return bridge.create_std__optional_double_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_double_ in
      if let __unwrappedValue = gap {
        return bridge.create_std__optional_double_(__unwrappedValue)
      } else {
        return .init()
      }
    }())
  }

  var trackHeight: Double? {
    @inline(__always)
    get {
      return self.__trackHeight.value
    }
    @inline(__always)
    set {
      self.__trackHeight = { () -> bridge.std__optional_double_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_double_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var progressHeight: Double? {
    @inline(__always)
    get {
      return self.__progressHeight.value
    }
    @inline(__always)
    set {
      self.__progressHeight = { () -> bridge.std__optional_double_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_double_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var thumbRadius: Double? {
    @inline(__always)
    get {
      return self.__thumbRadius.value
    }
    @inline(__always)
    set {
      self.__thumbRadius = { () -> bridge.std__optional_double_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_double_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var gap: Double? {
    @inline(__always)
    get {
      return self.__gap.value
    }
    @inline(__always)
    set {
      self.__gap = { () -> bridge.std__optional_double_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_double_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
}
