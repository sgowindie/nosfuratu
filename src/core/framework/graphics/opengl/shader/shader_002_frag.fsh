#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D u_TextureUnit;

varying vec2 v_TextureCoordinates;

void main()
{
    gl_FragColor = texture2D(u_TextureUnit, v_TextureCoordinates);
}
