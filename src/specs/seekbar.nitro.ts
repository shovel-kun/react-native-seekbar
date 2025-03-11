import type {
  HybridView,
  HybridViewProps,
  HybridViewMethods,
} from 'react-native-nitro-modules'

export interface SeekerColors {
  progressColor?: string
  disabledProgressColor?: string
  trackColor?: string
  disabledTrackColor?: string
  thumbColor?: string
  disabledThumbColor?: string
  readAheadColor?: string
}

export interface SeekerDimensions {
  trackHeight?: number
  progressHeight?: number
  thumbRadius?: number
  gap?: number
}

export interface SliderElementModifiers {
  readAheadColor?: string
  trackAlpha?: number
  readAheadAlpha?: number
  disabledTrackAlpha?: number
  disabledProgressAlpha?: number
  thumbRadius?: number
  trackHeight?: number
  gap?: number
  minSliderHeight?: number
  minSliderWidth?: number
  thumbDefaultElevation?: number
  thumbPressedElevation?: number
  thumbRippleRadius?: number
}

export interface Segment {
  name: string
  start: number
  color?: string
}

export interface SeekbarProps extends HybridViewProps {
  /**
   * Position of the video in seconds
   *
   * @default 0
   */
  position?: number
  /**
   * Duration of the video in seconds
   *
   * @default 0
   */
  duration?: number
  /**
   * Read ahead value in seconds
   */
  readAheadValue?: number
  /**
   * Callback when the position of the video changes
   */
  onValueChange?: (value: number) => void
  /**
   * Callback when the video finishes
   */
  onValueChangeFinished?: () => void
  /**
   * Callback when the segment changes
   */
  onSegmentChange?: (segment: Segment) => void
  /**
   * Segments of the video
   */
  segments?: Segment[]
  /**
   * Modifiers for the slider
   */
  // sliderModifiers?: SliderElementModifiers
  seekerColors?: SeekerColors
  seekerDimensions?: SeekerDimensions
}

export interface SeekbarMethods extends HybridViewMethods {}

export type Seekbar = HybridView<SeekbarProps, SeekbarMethods>
