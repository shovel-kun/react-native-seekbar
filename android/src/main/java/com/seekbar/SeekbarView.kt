package com.seekbar

import android.annotation.SuppressLint
import android.widget.FrameLayout
import androidx.compose.animation.core.animateDpAsState
import androidx.compose.foundation.interaction.MutableInteractionSource
import androidx.compose.foundation.interaction.collectIsDraggedAsState
import androidx.compose.material3.MaterialTheme
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableFloatStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.toArgb
import androidx.compose.ui.platform.ComposeView
import androidx.compose.ui.unit.dp
import androidx.core.graphics.toColorInt
import com.facebook.react.uimanager.ThemedReactContext
import dev.vivvvek.seeker.Seeker
import dev.vivvvek.seeker.SeekerDefaults
import dev.vivvvek.seeker.Segment
import dev.vivvvek.seeker.rememberSeekerState
import com.margelo.nitro.seekbar.SeekerColors as NitroSeekerColors
import com.margelo.nitro.seekbar.SeekerDimensions as NitroSeekerDimensions
import com.margelo.nitro.seekbar.Segment as NitroSegment

@SuppressLint("ViewConstructor")
class SeekbarView(context: ThemedReactContext) : FrameLayout(context) {
    private val composeView: ComposeView = ComposeView(context)
    var position by mutableFloatStateOf(0f)
    var duration by mutableFloatStateOf(0f)
    var readAheadValue by mutableFloatStateOf(0f)
    var onValueChange: (Float) -> Unit = {}
    var onValueChangeFinished: (() -> Unit) = {}
    var onSegmentChange: (NitroSegment) -> Unit = {}

    var segments: List<Segment> = listOf()
    var seekerColors: NitroSeekerColors? = null
    var seekerDimensions: NitroSeekerDimensions? = null


    @OptIn(ExperimentalStdlibApi::class)
    @Composable
    fun Seekbar() {
        // Use default dimensions and colors initially
        val defaultDimensions = SeekerDefaults.seekerDimensions()

        // Create a new SeekerDimensions instance that overrides only non-null properties
//        val dimensions = object : SeekerDimensions {
//            @SuppressLint("UnrememberedMutableState")
//            @Composable
//            override fun trackHeight(): State<Dp> {
//                val customTrackHeight = seekerDimensions?.trackHeight?.dp
//                return mutableStateOf(customTrackHeight ?: defaultDimensions.trackHeight().value)
//            }
//
//            @SuppressLint("UnrememberedMutableState")
//            @Composable
//            override fun progressHeight(): State<Dp> {
//                val customProgressHeight = seekerDimensions?.progressHeight?.dp
//                return mutableStateOf(customProgressHeight ?: defaultDimensions.progressHeight().value)
//            }
//
//            @SuppressLint("UnrememberedMutableState")
//            @Composable
//            override fun thumbRadius(): State<Dp> {
//                val customThumbRadius = seekerDimensions?.thumbRadius?.dp
//                return mutableStateOf(customThumbRadius ?: defaultDimensions.thumbRadius().value)
//            }
//
//            @SuppressLint("UnrememberedMutableState")
//            @Composable
//            override fun gap(): State<Dp> {
//                val customGap = seekerDimensions?.gap?.dp
//                return mutableStateOf(customGap ?: defaultDimensions.gap().value)
//            }
//        }

        val state = rememberSeekerState()

        // Enable animation
        val interactionSource = remember { MutableInteractionSource() }
        val isDragging by interactionSource.collectIsDraggedAsState()
        val gap by animateDpAsState(if (isDragging) 2.dp else 0.dp)
        val thumbRadius by animateDpAsState(if (isDragging) 10.dp else 0.dp)

        LaunchedEffect(state.currentSegment) {
            onSegmentChange(state.currentSegment.let { segment ->
                segment.let { segment ->
                    NitroSegment(
                        segment.name,
                        segment.start.toDouble(),
                        segment.color.toArgb().toHexString()
                    )
                }
            })
        }

        Seeker(
            state = state,
            value = position.coerceIn(0f, duration),
            range = 0f..duration,
            onValueChange = onValueChange,
            onValueChangeFinished = onValueChangeFinished,
            readAheadValue = readAheadValue,
            segments = segments
                .filter { it.start in 0f..duration }
                .let {
                    // add an extra segment at 0 if it doesn't exist.
                    if (it.isNotEmpty() && it[0].start != 0f) {
                        listOf(Segment("", 0f)) + it
                    } else {
                        it
                    } + it
                },
            interactionSource = interactionSource,
//            modifier = Modifier.padding(horizontal = 16.dp),
            dimensions = SeekerDefaults.seekerDimensions(gap = gap, thumbRadius = thumbRadius),
//            dimensions = dimensions,
            // For seekers color, we set our own default colors
            colors = SeekerDefaults.seekerColors(
                progressColor = seekerColors?.progressColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.primary,
                disabledProgressColor = seekerColors?.disabledProgressColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.primary,
                thumbColor = seekerColors?.thumbColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.primary,
                disabledThumbColor = seekerColors?.disabledThumbColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.primary,
                trackColor = seekerColors?.trackColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.background,
                disabledTrackColor = seekerColors?.disabledTrackColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.background,
                readAheadColor = seekerColors?.readAheadColor?.let { color ->
                    Color(color.toColorInt())
                } ?: MaterialTheme.colorScheme.inversePrimary,
            )
        )
    }

    init {
        composeView.setContent {
            Seekbar()
        }
        addView(composeView)
    }
}