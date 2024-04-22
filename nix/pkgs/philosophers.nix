{
  lib,
  stdenv,
}:
stdenv.mkDerivation (finalAttrs: {
  pname = "philosophers";
  version = "1.0.0";
  src = ../../philo;
  installPhase = ''
    mkdir -p $out/bin
    cp philo $out/bin
  '';
  meta = with lib; {
    license = licenses.agpl3;
    mainProgram = "philo";
  };
})
