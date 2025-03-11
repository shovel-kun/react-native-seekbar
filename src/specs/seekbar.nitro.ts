import type {
  HybridView,
  HybridViewProps,
  HybridViewMethods,
} from 'react-native-nitro-modules'
import type { Segment, SeekerColors, SeekerDimensions } from './types'

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
