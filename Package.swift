// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
  name: "YYAsyncLayer",
  products: [
    .library(
      name: "YYAsyncLayer",
      targets: ["YYAsyncLayer"]
    ),
  ],
  targets: [
    .target(
      name: "YYAsyncLayer",
      path: "YYAsyncLayer"
    ),
    .testTarget(
      name: "YYAsyncLayerTests",
      dependencies: ["YYAsyncLayer"]
    ),
  ]
)
