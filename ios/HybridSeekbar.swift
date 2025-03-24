import Foundation
import UIKit
import SwiftUI
import NitroModules

// MARK: - ViewModel
class HybridSeekbarViewModel: ObservableObject {
    @Published var value: Double = 0.0 {
        didSet {
            onValueChange?(value)
        }
    }
    @Published var bufferedValue: Double = 0.0
    @Published var durationValue: Double = 1.0
    @Published var seekerColors: SeekerColors?

    var onValueChange: ((Double) -> Void)?
    var onValueChangeFinished: (() -> Void)?

    var position: Double? = 0 {
        didSet {
            value = position ?? 0.0
        }
    }
    
    var readAheadValue: Double? = 0 {
        didSet {
            bufferedValue = readAheadValue ?? 0.0
        }
    }
    
    var duration: Double? = 0 {
        didSet {
            durationValue = duration ?? 1
        }
    }
}

// MARK: - SwiftUI View
struct SeekbarView: View {
    @ObservedObject var viewModel: HybridSeekbarViewModel
    
    var body: some View {
        SeekBar(value: $viewModel.value,
                bufferedValue: viewModel.bufferedValue,
                in: 0...viewModel.durationValue,
                onEditingChanged: { edited in
            if !edited {
                viewModel.onValueChangeFinished?()
            }
        })
        .handleColors(
            handleColor: .from(viewModel.seekerColors?.thumbColor, fallback: HandleDefaults.handleColor)
        )
        .trackColors(
            activeTrackColor: .from(viewModel.seekerColors?.progressColor, fallback: TrackDefaults.activeTrackColor),
            inactiveTrackColor: .from(viewModel.seekerColors?.trackColor, fallback: TrackDefaults.inactiveTrackColor),
            bufferedTrackColor: .from(viewModel.seekerColors?.readAheadColor, fallback: TrackDefaults.bufferedTrackColor)
        )
    }
}

// MARK: - UIKit Wrapper
class HybridSeekbar: HybridSeekbarSpec {
    private var viewModel = HybridSeekbarViewModel()
    
    // UIView
    var view: UIView {
        let swiftUIView = SeekbarView(viewModel: viewModel)
        let hostingController = UIHostingController(rootView: swiftUIView)
        return hostingController.view
    }
    
    var position: Double? {
        get { viewModel.position }
        set { viewModel.position = newValue }
    }
    
    var duration: Double? {
        get { viewModel.duration }
        set { viewModel.duration = newValue }
    }

    var readAheadValue: Double? {
        get { viewModel.readAheadValue }
        set { viewModel.readAheadValue = newValue }
    }
    
    var onValueChange: ((Double) -> Void)? {
        didSet {
            viewModel.onValueChange = onValueChange
        }
    }
    
    var onValueChangeFinished: (() -> Void)? {
        didSet {
            viewModel.onValueChangeFinished = onValueChangeFinished
        }
    }

    var seekerColors: SeekerColors? {
        get { viewModel.seekerColors }
        set { viewModel.seekerColors = newValue }
    }

    var seekerDimensions: SeekerDimensions?

    var segments: [Segment]?
    
    var onSegmentChange: ((Segment) -> Void)?
}
