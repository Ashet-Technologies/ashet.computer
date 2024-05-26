{
  description = "The website of Ashet Technologies";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-23.11";
    flake-utils.url = "github:numtide/flake-utils";
    zig.url = "github:mitchellh/zig-overlay";

    # Used for shell.nix
    flake-compat = {
      url = "github:edolstra/flake-compat";
      flake = false;
    };
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
    ...
  } @ inputs: let
    overlays = [
      # Other overlays
      (final: prev: {
        zigpkgs = inputs.zig.packages.${prev.system};
      })
    ];

    # Our supported systems are the same supported systems as the Zig binaries
    systems = builtins.attrNames inputs.zig.packages;
  in
    flake-utils.lib.eachSystem systems (
      system: let
        pkgs = import nixpkgs {inherit overlays system;};
      in let
        zig = pkgs.zigpkgs.master;
      in rec {
        packages.default = pkgs.stdenv.mkDerivation {
          name = "ashet.computer";
          src = ./.;
          nativeBuildInputs = [
            zig
          ];

          configurePhase = "";

          buildPhase = ''
            zig build
          '';

          installPhase = ''
            mv zig-out $out
          '';
        };
      }
    );
}
