//
//  ColorExtension.swift
//  Pods
//
//  Created by user on 23/3/25.
//

import SwiftUI

extension Color {
    static func from(_ value: Any?, fallback: Color) -> Color {
        if let uiColor = UIColor.convert(from: value) {
            return Color(uiColor)
        } else {
            return fallback
        }
    }
}
