///
/// HybridSeekbarSpec.kt
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

package com.margelo.nitro.seekbar

import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.*
import com.margelo.nitro.views.*

/**
 * A Kotlin class representing the Seekbar HybridObject.
 * Implement this abstract class to create Kotlin-based instances of Seekbar.
 */
@DoNotStrip
@Keep
@Suppress(
  "KotlinJniMissingFunction", "unused",
  "RedundantSuppression", "RedundantUnitReturnType", "SimpleRedundantLet",
  "LocalVariableName", "PropertyName", "PrivatePropertyName", "FunctionName"
)
abstract class HybridSeekbarSpec: HybridView() {
  @DoNotStrip
  private var mHybridData: HybridData = initHybrid()

  init {
    super.updateNative(mHybridData)
  }

  override fun updateNative(hybridData: HybridData) {
    mHybridData = hybridData
    super.updateNative(hybridData)
  }

  // Properties
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var position: Double?
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var duration: Double?
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var readAheadValue: Double?
  
  abstract var onValueChange: ((value: Double) -> Unit)?
  
  private var onValueChange_cxx: Func_void_double?
    @Keep
    @DoNotStrip
    get() {
      return onValueChange?.let { Func_void_double_java(it) }
    }
    @Keep
    @DoNotStrip
    set(value) {
      onValueChange = value?.let { it }
    }
  
  abstract var onValueChangeFinished: (() -> Unit)?
  
  private var onValueChangeFinished_cxx: Func_void?
    @Keep
    @DoNotStrip
    get() {
      return onValueChangeFinished?.let { Func_void_java(it) }
    }
    @Keep
    @DoNotStrip
    set(value) {
      onValueChangeFinished = value?.let { it }
    }
  
  abstract var onSegmentChange: ((segment: Segment) -> Unit)?
  
  private var onSegmentChange_cxx: Func_void_Segment?
    @Keep
    @DoNotStrip
    get() {
      return onSegmentChange?.let { Func_void_Segment_java(it) }
    }
    @Keep
    @DoNotStrip
    set(value) {
      onSegmentChange = value?.let { it }
    }
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var segments: Array<Segment>?
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var seekerColors: SeekerColors?
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var seekerDimensions: SeekerDimensions?

  // Methods
  

  private external fun initHybrid(): HybridData

  companion object {
    private const val TAG = "HybridSeekbarSpec"
  }
}
