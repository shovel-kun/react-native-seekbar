package com.seekbar

import android.util.Log
import androidx.annotation.Keep
import com.facebook.proguard.annotations.DoNotStrip
import com.facebook.react.uimanager.ThemedReactContext
import com.margelo.nitro.seekbar.HybridSeekbarSpec
import com.margelo.nitro.seekbar.SeekerColors as NitroSeekerColors
import com.margelo.nitro.seekbar.SeekerDimensions as NitroSeekerDimensions
import com.margelo.nitro.seekbar.Segment
import androidx.core.graphics.toColorInt
import androidx.compose.ui.graphics.Color

@Keep
@DoNotStrip
class HybridSeekbar(context: ThemedReactContext): HybridSeekbarSpec() {
    // View
    override val view = SeekbarView(context)

    // TODO: Props keep rerendering when position changes, find a way to mitigate this
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

    override var segments: Array<Segment>? = null
        set(value) {
            if (field == value) return
            field = value
            view.segments = value?.map { dev.vivvvek.seeker.Segment(it.name, it.start.toFloat(), it.color?.let { color -> Color(color.toColorInt()) } ?: Color.Unspecified) } ?: listOf()
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

    override var onSegmentChange: ((Segment) -> Unit)? = {}
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
