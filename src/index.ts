import { getHostComponent, type HybridRef } from 'react-native-nitro-modules'
import SeekbarConfig from '../nitrogen/generated/shared/json/SeekbarConfig.json'
import type { SeekbarProps, SeekbarMethods } from './specs/seekbar.nitro'

export const Seekbar = getHostComponent<SeekbarProps, SeekbarMethods>(
  'Seekbar',
  () => SeekbarConfig
)

export type SeekbarRef = HybridRef<SeekbarProps, SeekbarMethods>
