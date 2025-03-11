package com.seekbar

import android.util.Log
import androidx.annotation.Keep
import androidx.compose.ui.graphics.Color
import androidx.core.graphics.toColorInt
import com.facebook.proguard.annotations.DoNotStrip
import com.facebook.react.uimanager.ThemedReactContext
import com.margelo.nitro.seekbar.HybridSeekbarSpec
import dev.vivvvek.seeker.Segment
import com.margelo.nitro.seekbar.SeekerColors as NitroSeekerColors
import com.margelo.nitro.seekbar.SeekerDimensions as NitroSeekerDimensions
import com.margelo.nitro.seekbar.Segment as NitroSegment

@Keep
@DoNotStrip
class HybridSeekbar(context: ThemedReactContext) : HybridSeekbarSpec() {
    // View
    override val view = SeekbarView(context)

    // TODO: Props keep re-rendering when position changes, find a way to mitigate this
    // NOTE: Props wont be set if they haven't changed automatically in RN 0.79

    // Props
    override var position: Double? = null
        set(value) {
            Log.i("VLC", "position: $value")
            if (field == value) return
            field = value
            view.position = value?.toFloat() ?: 0f
        }

    override var duration: Double? = null
        set(value) {
            if (field == value) return
            field = value
            view.duration = value?.toFloat() ?: 0f
        }

    override var readAheadValue: Double? = null
        set(value) {
            if (field == value) return
            field = value
            view.readAheadValue = value?.toFloat() ?: 0f
        }

    override var segments: Array<NitroSegment>? = null
        set(value) {
            if (field == value) return
            field = value
            view.segments = value?.map {
                Segment(
                    it.name,
                    it.start.toFloat(),
                    it.color?.let { color -> Color(color.toColorInt()) } ?: Color.Unspecified)
            } ?: listOf()
        }

    override var onValueChange: ((Double) -> Unit)? = null
        set(value) {
            if (field == value) return
            field = value
            view.onValueChange = { this@HybridSeekbar.onValueChange?.invoke(it.toDouble()) }
        }

    override var onValueChangeFinished: (() -> Unit)? = null
        set(value) {
            if (field == value) return
            field = value
            view.onValueChangeFinished = { this@HybridSeekbar.onValueChangeFinished?.invoke() }
        }

    override var onSegmentChange: ((NitroSegment) -> Unit)? = {}
        set(value) {
            if (field == value) return
            field = value
            view.onSegmentChange = { this@HybridSeekbar.onSegmentChange?.invoke(it) }
        }

    override var seekerColors: NitroSeekerColors? = null
        set(value) {
            if (field == value) return
            field = value
            view.seekerColors = value
        }

    override var seekerDimensions: NitroSeekerDimensions? = null
        set(value) {
            if (field == value) return
            field = value
            view.seekerDimensions = value
        }
}
