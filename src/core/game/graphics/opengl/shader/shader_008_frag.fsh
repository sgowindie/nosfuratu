#ifdef GL_ES
precision highp float;
#endif

uniform sampler2D u_from;
uniform sampler2D u_to;
uniform float u_progress;

varying vec2 v_TextureCoordinates;
varying vec2 v_Center;

const float SQRT_2 = 1.414213562373;

void main()
{
    vec2 p = v_TextureCoordinates;
    vec2 center = vec2(v_Center.x, v_Center.y);
    float x = u_progress;
    
    vec4 black = vec4(0, 0, 0, 1);
    
    if (x <= 0.49)
    {
        x = x * 2.04081632653061;
        x = 1.0 - x;
        
        float smoothness = 0.1;
        float m = smoothstep(-smoothness, 0.0, SQRT_2 * distance(center, p) - x * (1.8 + smoothness));
        gl_FragColor = mix(black, texture2D(u_from, p), 1.0 - m);
    }
    else if (x >= 0.51)
    {
        x = x - 0.51;
        x = x * 2.04081632653061;
        
        float smoothness = 0.1;
        float m = smoothstep(-smoothness, 0.0, SQRT_2 * distance(center, p) - x * (1.8 + smoothness));
        gl_FragColor = mix(black, texture2D(u_to, p), 1.0 - m);
    }
    else
    {
        gl_FragColor = black;
    }
}
