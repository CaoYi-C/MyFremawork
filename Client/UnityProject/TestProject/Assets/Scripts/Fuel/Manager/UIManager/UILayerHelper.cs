using System;
using System.Collections.Generic;
using UnityEngine;

namespace Fuel.Manager.UIManager
{
    public static class UILayerHelper
    {
        private const int Z_SPACING = 1000;

        public static int GetZ(UILayer layer)
        {
            return (int)layer * Z_SPACING;
        }

        public static string GetLayerName(UILayer layer)
        {
            return layer.ToString();
        }

        public static bool IsHigherLayer(UILayer layer1, UILayer layer2)
        {
            return (int)layer1 > (int)layer2;
        }
    }
}
