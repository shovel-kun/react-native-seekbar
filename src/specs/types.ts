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
