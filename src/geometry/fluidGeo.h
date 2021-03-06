#ifndef FLUID_GEO_H
#define FLUID_GEO_H

#include <geometry/geometry.h>
#include <vector>

class FluidGeo : public Geometry
{
public:
    FluidGeo(
        const vector<glm::vec3>& positions,
        const vector<glm::vec3>& velocities,
        const vector<float>& spawnTimes,
        const vector<glm::vec4>& colors
        );

    virtual void Create();
    virtual GLenum GLDrawMode() const;

    // Override to update transform feedback buffers
    virtual void EnableVertexAttributes() const;
    virtual void DisableVertexAttributes() const;

    // Vao -> vertex array object
    virtual void UpdateVao();

    void ToggleVao();

    // Getters/Setters
    GLuint PosBuffer() const;
    GLuint VelBuffer() const;
    GLuint SpawnTimeBuffer() const;
    GLuint ColBuffer() const;
    void SetVelocities(const vector<glm::vec3>& velocities) {
        m_velocities = velocities;
    }

protected:
    virtual void InitIndices();

    vector<glm::vec3> m_velocities;
    vector<float> m_spawnTimes;

    // -- Secondary vao to ping-pong transform feedback

    // Which vao we are using
    bool m_useVao2;

    // Vertex buffers
    GLuint m_posBuffer2;

    GLuint m_velBuffer;
    GLuint m_velBuffer2;

    GLuint m_spawnTimeBuffer;
    GLuint m_spawnTimeBuffer2;

    GLuint m_colBuffer2;

    // Vertex array object
    GLuint m_vao2;
};

#endif
