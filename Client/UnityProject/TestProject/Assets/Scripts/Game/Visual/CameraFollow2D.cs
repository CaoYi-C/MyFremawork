using UnityEngine;

namespace Game.Visual
{
    public sealed class CameraFollow2D : MonoBehaviour
    {
        [SerializeField] private Transform target;
        [SerializeField] private string targetName = "Character";
        [SerializeField] private Vector2 offset = new Vector2(0f, 1f);
        [SerializeField, Min(0f)] private float smoothTime = 0.15f;
        [SerializeField] private bool followX = true;
        [SerializeField] private bool followY = true;

        private Vector3 _velocity;

        private void LateUpdate()
        {
            if (target == null)
                TryFindTarget();

            if (target == null) return;

            Vector3 current = transform.position;
            Vector3 desired = new Vector3(
                followX ? target.position.x + offset.x : current.x,
                followY ? target.position.y + offset.y : current.y,
                current.z);

            transform.position = smoothTime <= 0f
                ? desired
                : Vector3.SmoothDamp(current, desired, ref _velocity, smoothTime);
        }

        private void TryFindTarget()
        {
            var go = GameObject.Find(targetName);
            if (go != null)
                target = go.transform;
        }
    }
}
