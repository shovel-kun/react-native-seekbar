//
//  Conversions.swift
//  Pods
//
//  Created by user on 23/3/25.
//

import UIKit

// Define custom exceptions
public enum HexColorError: Error {
    case invalidHexColor(String)
    case hexColorOverflow(UInt64)
}

public struct InvalidHexColorException: Error {
    let hexString: String
    
    init(_ hexString: String) {
        self.hexString = hexString
    }
    
    var localizedDescription: String {
        return "Invalid hex color string: \(hexString)"
    }
}

public struct HexColorOverflowException: Error {
    let value: UInt64
    
    init(_ value: UInt64) {
        self.value = value
    }
    
    var localizedDescription: String {
        return "Hex color value overflow: \(value)"
    }
}

public struct Conversions {
    /**
     Converts hex string to `UIColor` or throws an exception if the string is corrupted.
     */
    static func toColor(hexString hex: String) throws -> UIColor {
        var hexStr = hex
            .trimmingCharacters(in: .whitespacesAndNewlines)
            .replacingOccurrences(of: "#", with: "")
        
        // If just RGB, set alpha to maximum
        if hexStr.count == 6 { hexStr += "FF" }
        if hexStr.count == 3 { hexStr += "F" }
        
        // Expand short form (supported by Web)
        if hexStr.count == 4 {
            let chars = Array(hexStr)
            hexStr = [
                String(repeating: chars[0], count: 2),
                String(repeating: chars[1], count: 2),
                String(repeating: chars[2], count: 2),
                String(repeating: chars[3], count: 2)
            ].joined(separator: "")
        }
        
        var rgba: UInt64 = 0
        
        guard hexStr.range(of: #"^[0-9a-fA-F]{8}$"#, options: .regularExpression) != nil,
              Scanner(string: hexStr).scanHexInt64(&rgba) else {
            throw InvalidHexColorException(hex)
        }
        return try toColor(rgba: rgba)
    }
    
    /**
     Converts an integer for ARGB color to `UIColor`. Since the alpha channel is represented by first 8 bits,
     it's optional out of the box. React Native converts colors to such format.
     */
    static func toColor(argb: UInt64) throws -> UIColor {
        guard argb <= UInt32.max else {
            throw HexColorOverflowException(argb)
        }
        let alpha = CGFloat((argb >> 24) & 0xff) / 255.0
        let red   = CGFloat((argb >> 16) & 0xff) / 255.0
        let green = CGFloat((argb >> 8) & 0xff) / 255.0
        let blue  = CGFloat(argb & 0xff) / 255.0
        return UIColor(red: red, green: green, blue: blue, alpha: alpha)
    }
    
    /**
     Converts an integer for RGBA color to `UIColor`.
     */
    static func toColor(rgba: UInt64) throws -> UIColor {
        guard rgba <= UInt32.max else {
            throw HexColorOverflowException(rgba)
        }
        let red   = CGFloat((rgba >> 24) & 0xff) / 255.0
        let green = CGFloat((rgba >> 16) & 0xff) / 255.0
        let blue  = CGFloat((rgba >> 8) & 0xff) / 255.0
        let alpha = CGFloat(rgba & 0xff) / 255.0
        return UIColor(red: red, green: green, blue: blue, alpha: alpha)
    }
}
