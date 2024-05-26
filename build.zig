const std = @import("std");
const zine = @import("zine");

pub fn build(b: *std.Build) !void {
    try zine.addWebsite(b, .{
        .title = "Ashet Technologies",
        .host_url = "https://ashet.computer",
        .layouts_dir_path = "layouts",
        .content_dir_path = "content",
        .static_dir_path = "static",
    });
}