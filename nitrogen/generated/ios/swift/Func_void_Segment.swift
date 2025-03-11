///
/// Func_void_Segment.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Wraps a Swift `(_ segment: Segment) -> Void` as a class.
 * This class can be used from C++, e.g. to wrap the Swift closure as a `std::function`.
 */
public final class Func_void_Segment {
  public typealias bridge = margelo.nitro.seekbar.bridge.swift

  private let closure: (_ segment: Segment) -> Void

  public init(_ closure: @escaping (_ segment: Segment) -> Void) {
    self.closure = closure
  }

  @inline(__always)
  public func call(segment: Segment) -> Void {
    self.closure(segment)
  }

  /**
   * Casts this instance to a retained unsafe raw pointer.
   * This acquires one additional strong reference on the object!
   */
  @inline(__always)
  public func toUnsafe() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(self).toOpaque()
  }

  /**
   * Casts an unsafe pointer to a `Func_void_Segment`.
   * The pointer has to be a retained opaque `Unmanaged<Func_void_Segment>`.
   * This removes one strong reference from the object!
   */
  @inline(__always)
  public static func fromUnsafe(_ pointer: UnsafeMutableRawPointer) -> Func_void_Segment {
    return Unmanaged<Func_void_Segment>.fromOpaque(pointer).takeRetainedValue()
  }
}
